#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int k[maxn];
int n;
const int mod=998244353;
int c[maxn][maxn];
long long C(int a,int b)
{
	b=min(b,a-b);
	long long h=1;
	for(int i=b;i>=2;i--)
	{
		h=(h*i)%mod;
	}
	long long g=1;
	for(int i=a;i>a-b;i--)
	{
		g=(g*i)%mod;
	}
	c[a][b]=(g/h)%mod;
	return (g/h)%mod;
}
void sol()
{
	memset(c,0,sizeof(c));
	long long ans=0;
	for(int i=1;i<=n;i++) c[i][1]=i;
	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=i;j++)
		{
			if(c[i][i-j]) 
			ans=(ans+c[i][i-j])%mod;
			else{
				ans+=C(i,j);
			}
		}
	}
	cout<<ans;
}
int sumx[maxn];
long long ans2=0;
void dfs(int i,int x,int sumx)
{
//	cout<<sumx<<" "<<x<<" "<<k[i]<<endl;
	if(sumx+k[x]>k[i]) 
	{
		ans2=(ans2+1)%mod;
	 } 
	if(x==i-1)
	{
		return ;
	}
		for(int j=x+1;j<=i-1;j++)
		{
			dfs(i,j,sumx+k[x]);
		}
}
void sol2()
{
//	for(int i=1;i<=n;i++) sumx[i]=(sumx[i-1]+k[i])%mod;
	for(int i=3;i<=n;i++)
	{
		for(int a=1;a<=i-2;a++)
		{
		//	cout<<i<<" "<<a<<" "<<k[a]<<":"<<endl;
			dfs(i,a,0);
		 } 
	}
	cout<<ans2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>k[i];
	}
	if(n>=500)
	{
		sol();
		return 0;
	}
	else{
		sort(k+1,k+1+n);
		sol2();
	}
	return 0;
 } 
