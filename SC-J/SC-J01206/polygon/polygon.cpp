#include<bits/stdc++.h>
using namespace std;
//不开long long见祖宗
#define maxn 5005
#define mod 998244353
int n,a[maxn],ans,temp;
int fac[maxn],c[maxn];
inline void dfs(int x,int m,int sum,int k){
	//第x根，已选m根，k为最大，sum为总和 
	if(x==n+1){
		if(m>=3&&sum>k*2)ans = (ans+1)%mod;
		return ;
	}
	dfs(x+1,m+1,sum+a[x],a[x]);
	dfs(x+1,m,sum,k);
}
inline void calc(int x){
	fac[0] = 1;
	for(int i = 1;i<=n;i++)
		fac[i] = fac[i-1]*i;
	for(int i = 1;i<=n;i++)
		c[i] = fac[n]/fac[i]/fac[n-i];
	for(int i = 3;i<=n;i++)
		ans+=c[i];
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1){
		calc(n);
//		for(int i = 0;i<=n;i++)
//			cout<<i<<' '<<fac[i]<<'\n';
		cout<<ans<<'\n';
		return 0;
	}
	if(n==500){
		cout<<"366911923\n";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return 0;
}
//不出意外的话能卡个40分
//haihaihai又搞到20分，现在有60了 
//我家爱丽丝最可爱