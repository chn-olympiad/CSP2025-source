#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],s=0;
int mod=998244353;
int f[5005],p[5005];
void dfs(int ans,int k,int dep,int sum,int mx){
	if(dep>k){
		if(sum>2*mx)s++;
		ans%=mod;
		return;
	}
	if(ans==n)return;
	for(int i=ans+1;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		dfs(i,k,dep+1,sum+a[i],max(mx,a[i]));
		f[i]=0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int ff=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[1]!=1)ff=1;
	}
	if(ff==0){
		int su=0;
		p[0]=1;
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]*i;
			p[i]%=mod;
		}
		for(int i=3;i<=n;i++){
			su+=p[n]/(p[i]*p[n-i]);
			su%=mod;
		}
		cout<<su;
		return 0;
	}
	for(int i=3;i<=n;i++){
		memset(f,0,sizeof(f));
		dfs(0,i,1,0,0);
	}
	cout<<s;
    return 0;
}
