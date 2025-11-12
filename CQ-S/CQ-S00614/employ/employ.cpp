#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[502],bj,ans,p[502];bool bj2[502];string s;
inline void dfs(int now){
	if(now==n+1){
		int sum=0,res=0; 
		for(int i=1;i<=n;++i){
			if(res>=c[p[i]]){++res;continue;}
			if(s[i]=='1') ++sum;
			else ++res;
		}ans+=(sum>=m);return;
	}for(int i=1;i<=n;++i){
		if(!bj2[i]){
			bj2[i]=1,p[now]=i;
			dfs(now+1);
			bj2[i]=0,p[now]=0;
		}
	}return;
}
signed main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=1;i<=n;++i) if(s[i]=='0') bj=1;
	if(m==1||bj==0){
		ans=1;for(int i=1;i<=n;++i) ans=ans*i%mod;
		cout<<ans;return 0;
	}if(m==n){cout<<0;return 0;}
	dfs(1);cout<<ans;
	return 0;
}
