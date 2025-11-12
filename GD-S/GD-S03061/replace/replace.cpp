#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
inline void cmax(int&x,int y){x=(x>y?x:y);}
inline void cmin(int&x,int y){x=(x<y?x:y);}
const int mod=998244853,base=19260817;
int n,q,pw[5000005];
int g(string s,int l,int r){
	int hsh=0;
	fo(i,l,r)hsh=(1ll*hsh*base+1ll*s[i])%mod;
	return hsh;
}
string s,t;
map<pii,int>mp;
int cnt,hsh[5000005],hsh2[5000005];
inline int ghsh(int*h,int l,int r){return (1ll*h[r]-1ll*h[l-1]*pw[r-l+1]%mod+mod)%mod;}
vector<int>v[200005];
inline void solve(){
	cin>>n>>q;
	fo(i,1,n){
		cin>>s>>t;
		int r=-1;
		fo(i,0,s.size()-1)if(s[i]!=t[i])r=i;
		if(r<0)continue;
		int t1=g(s,0,r),t2=g(t,0,r);
		if(!mp.count({t1,t2}))mp[{t1,t2}]=++cnt;
		v[mp[{t1,t2}]].pb(g(s,r+1,s.size()-1));
//		cout<<t1<<' '<<t2<<' '<<g(s,r+1,s.size()-1)<<'\n';
	}
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){cout<<"0\n";continue;}
		int l=-1,r;
		fo(i,0,s.size()-1)if(s[i]!=t[i]){
			r=i;
			if(l<0)l=i;
		}
		fo(i,0,s.size()-1)hsh[i]=(1ll*hsh[i-1]*base+1ll*s[i])%mod,hsh2[i]=(1ll*hsh2[i-1]*base+1ll*t[i])%mod;
		unordered_map<int,int>tmp;
		fo(i,r,s.size()-1)tmp[ghsh(hsh,r+1,i)]=1;
		int ans=0;
		fo(i,0,l){
			int t1=ghsh(hsh,i,r),t2=ghsh(hsh2,i,r);
			if(mp.count({t1,t2})){
				int t=mp[{t1,t2}];
				for(int j:v[t])ans+=tmp[j];
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	pw[0]=1;
	fo(i,1,5e6)pw[i]=1ll*pw[i-1]*base%mod;
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
