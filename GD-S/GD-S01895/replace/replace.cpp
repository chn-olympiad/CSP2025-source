#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ull unsigned ll
const int N=5e6+5,mod=1e9+7,P=133;
ll pw[N],len[N],ipw[N];ll sum[N][2];
vector<int>nxt[N];
map<pii,int>cnt;
ll qp(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod,y>>=1;}return res;}
ll hsh(string s){
	ll res=0;
	for(int i=1;i<s.size();i++)
		res=(res+1ll*(s[i]-'a')*pw[i]%mod)%mod; 
	return res%mod;
}
string a[N],b[N],s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q,L=0,B;
	cin>>n>>q;pw[0]=ipw[0]=1;
	for(int i=1;i<=5e6;i++)
		pw[i]=1ll*pw[i-1]*P%mod,ipw[i]=qp(pw[i],mod-2);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len[i]=a[i].size();a[i]=' '+a[i],b[i]=' '+b[i],L+=len[i];
		nxt[i].resize(len[i]+1);int j=0;
		for(int k=2;k<=len[i];k++){
			while(j&&a[i][k]!=a[i][j+1])j=nxt[i][j];
			if(a[i][k]==a[i][j+1])++j;nxt[i][k]=j;
		}
	}
	B=sqrt(L);vector<int>o; 
	for(int i=1;i<=n;i++)
		if(len[i]>B)o.pb(i);
		else cnt[mp(hsh(a[i]),hsh(b[i]))]+=1;
	int cas=0,lst=0;
	while(q--){
		++cas;
		cin>>s>>t;
		int l=s.size(),ans=0;	
		if(s.size()!=t.size()){
			cout<<0<<'\n';
			continue;
		}
		s=' '+s,t=' '+t;
		for(int i=1;i<=l;i++)
			sum[i][0]=(sum[i-1][0]+1ll*(s[i]-'a')*pw[i]%mod)%mod,
			sum[i][1]=(sum[i-1][1]+1ll*(t[i]-'a')*pw[i]%mod)%mod;
		if(n<=100){
			for(int p=1;p<=n;p++){
			int j=0;
			for(int i=1;i<=l;i++){
				while(j&&s[i]!=a[p][j+1])j=nxt[p][j];
				if(s[i]==a[p][j+1])++j;
				if(j==len[p]){
					int u=i-len[p]+1;
					if((sum[l][0]+mod-sum[i][0])%mod==(sum[l][1]+mod-sum[i][1])%mod&&
					   sum[u-1][0]==sum[u-1][1]&&(sum[i][1]+mod-sum[u-1][1])%mod*ipw[u-1]%mod==hsh(b[p]))++ans;
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int p:o){
			int j=0;
			for(int i=1;i<=l;i++){
				while(j&&s[i]!=a[p][j+1])j=nxt[p][j];
				if(s[i]==a[p][j+1])++j;
				if(j==len[p]){
					int u=i-len[p]+1;
					if((sum[l][0]+mod-sum[i][0])%mod==(sum[l][1]+mod-sum[i][1])%mod&&
					   sum[u-1][0]==sum[u-1][1]&&(sum[i][1]+mod-sum[u-1][1])%mod*ipw[u-1]%mod==hsh(b[p]))++ans;
				}
			}
		}
		for(int i=1;i<=l;i++)
			for(int j=i;j<=min(l,i+B-1);j++){
				if((sum[l][0]+mod-sum[j][0])%mod==(sum[l][1]+mod-sum[j][1])%mod&&sum[i-1][0]==sum[i-1][1]){
					pii res=mp((sum[j][0]+mod-sum[i-1][0])%mod*ipw[i-1]%mod,(sum[j][1]+mod-sum[i-1][1])%mod*ipw[i-1]%mod);
					if(cnt.count(res))ans+=cnt[res];
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
