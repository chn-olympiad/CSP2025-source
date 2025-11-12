#include<bits/stdc++.h>
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define ad(k) (k=-~k)
using namespace std;const int N=5e3+2,mod=998244353;
int n,a[N];long long ans;
inline void dfs(int id,int sum,int num){
	if(num>=2&&sum>a[id])ans=(ans+1)%mod;
	F(i,id+1,n)dfs(i,sum+a[id],num+1);
	return;
}int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	cin>>n;
	F(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	F(i,1,n)dfs(i,0,0);
	cout<<ans; 
	return 0;
}
