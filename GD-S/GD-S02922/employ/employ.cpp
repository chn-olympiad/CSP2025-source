#include "bits/stdc++.h"
using namespace std;
#define int long long
static const int mod=998244353;
int n,m,ans;
int c[505],s[505],w[505],bz[505];
void dg(int x){
	if(x>n){
		int res=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(!s[i] || res>=c[w[i]]) res++;
			else cnt++;
		return void(ans+=(cnt>=m));	
	}
	for(int i=1;i<=n;i++)
		if(!bz[i]) w[x]=i,bz[i]=1,dg(x+1),bz[i]=0;
}
signed main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0,flag=0,answer=1;
	for(int i=1;i<=n;i++) scanf("%1lld",&s[i]),sum+=s[i],answer=answer*i%mod;
	for(int i=1;i<=n;i++) cin>>c[i],flag=flag || c[i]==0;
	if(n==m){
		if(sum!=n) return cout<<0,0;
		else if(flag) return cout<<0,0;
		else return cout<<answer,0; 
	}
	dg(1);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
}
