#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define mset multiset
#define pq priority_queue
#define ull unsigned long long
#define i128 __int128
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=2e5+10,maxl=5e6+10;
const int base=131,mod=998244353;
int n,q,pw[maxl],id[maxl],cnt,len[maxn];
bool flg[maxn];
string s1,s2,t1[maxn],t2[maxn];
vector<int> vec;
vector<ll> num[maxn];
umap<ll,int> mp;
ll res[maxn];
void solve(){
	cin>>n>>q,pw[0]=1;
	for(int i=1;i<=5e6;i++) pw[i]=(1ll*pw[i-1]*base)%mod;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int h1=0,h2=0,len=s1.size();
		for(char c:s1) h1=(1ll*h1*base+c)%mod;
		for(char c:s2) h2=(1ll*h2*base+c)%mod;
		if(!id[len]) vec.pb(len),id[len]=++cnt;
		num[id[len]].pb(1000000000ll*h1+h2);
	}
//	for(int i=1;i<=cnt;i++) work(num[i]);
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i],flg[i]=(t1[i].size()!=t2[i].size()),len[i]=t1[i].size();
	int idx=0;
	for(int x:vec){
		mp.clear(),idx++;
		for(ll nums:num[idx]) mp[nums]++;
		for(int i=1;i<=q;i++){
			if(flg[i]||x>len[i]) continue;
			int h1=0,h2=0,cnt=0;
			for(int j=x;j<len[i];j++) cnt+=(t1[i][j]==t2[i][j]);
			for(int j=0;j<x-1;j++) h1=(1ll*h1*base+t1[i][j])%mod;
			for(int j=0;j<x-1;j++) h2=(1ll*h2*base+t2[i][j])%mod;
			for(int j=x-1;j<len[i];j++){
				h1=(1ll*h1*base+t1[i][j])%mod,h2=(1ll*h2*base+t2[i][j])%mod;
//				cout<<j-x+1<<" "<<j<<" "<<h1<<" "<<h2<<endl;
				if(cnt==len[i]-x) res[i]+=mp[1000000000ll*h1+h2];
				h1=(h1-1ll*pw[x-1]*t1[i][j-x+1]%mod+mod)%mod;
				h2=(h2-1ll*pw[x-1]*t2[i][j-x+1]%mod+mod)%mod;
				cnt-=(t1[i][j+1]==t2[i][j+1]),cnt+=(t1[i][j-x+1]==t2[i][j-x+1]);
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<res[i]<<endl;
}
int main(){
	FileIO("replace");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}

