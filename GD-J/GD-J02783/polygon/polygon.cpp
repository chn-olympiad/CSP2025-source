#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,a[5001],dp[2][5001],s,b[5002],p=998244353;
void dfs(int i=1,int mx=0,int sum=0){
	if(i>n){
		if(sum>mx*2)s++;
		return;
	}
	if(sum+b[i]<=2*mx)return;
	dfs(i+1,mx,sum),dfs(i+1,max(mx,a[i]),sum+a[i]);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=n;i;i--)b[i]=b[i+1]+a[i];
	if(b[1]/n==1){
		for(int i=1;i<=n-3;i++){
			dp[i%2][0]=dp[i%2][i]=1;
			for(int j=1;j<i;j++)dp[i%2][j]=(dp[(i+1)%2][j-1]+dp[(i+1)%2][j])%p;
		}
		for(int i=1;i<=n-3;i++)(s+=dp[(n-3)%2][i])%=p;
		cout<<s;return 0;
	}
	dfs();
	cout<<s;
	return 0;
}
