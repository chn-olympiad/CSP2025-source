#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[5005];
long long c[5005][5005];
long long sum[5005];
long long S[5005];
int l[5005];
int n;
int ans=0;
void f()
{
	c[1][1]=1;
	sum[1]=1;
	for(int i=2;i<=5001;i++)
	{
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
			sum[i]=(sum[i]%M+c[i][j]%M)%M;
		}
	}
}
void dfs(int p,int s,int mx,int cnt)
{
	if(s+S[n]-S[p-1]<=mx*2)return ;
	if(s+a[p]>mx*2&&s!=0&&cnt>=3)
	{
		ans+=sum[n-p+1]%M;
		dfs(p+1,s,mx,cnt);
		return ;
	}
	if(p==n+1)
	{
		if(s>mx*2)ans++;
		return ;
	}
	dfs(p+1,s+a[p],max(mx,a[p]),cnt+1);
	dfs(p+1,s,mx,cnt);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	f();
	int ok=1;
	for(int i=1;i<=n;i++)
	{ 
		scanf("%d",&a[i]);
		if(a[i]!=1)ok=0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		S[i]=(S[i-1]+a[i])%M;
	}
	if(ok)
	{
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			ans+=c[n+1][i+1]%M;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,1);
	cout<<ans%M;
	return 0;
}
/*
4 3
2 1 0 3
*/
