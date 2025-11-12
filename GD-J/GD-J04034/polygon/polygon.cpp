#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],c[5010][5010],s=0;
struct dp{
	int ma,sum;
}f[5010][5010];
void dfs(int l,int sum,int ma,int h){
	if(l>n)
	{
		if(sum>2*ma&&h>2)
			s++;
		return ;
	}
	dfs(l+1,sum+a[l],a[l],h+1);
	dfs(l+1,sum,ma,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]; 
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[3]<=a[1]+a[2])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(a[n]==1)
	{
		c[1][1]=1;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++)
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		for(int i=3;i<=n;i++)
			s=(s+c[n][i])%mod;
		cout<<s;
		return 0;
	}
	if(n<=30)
	{
		dfs(1,0,0,0);
		cout<<s;
	}
	return 0;
}
