#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
const int N=511;
const int P=998244353;
int n,m;
int a[N];
int vis[N];
int f[N];
int c[N];
string s;
int num;
long long C(int x,int y)
{
	int num1=1;
	for(int i=x+1;i<=y;i++)
		num1=(num1*i)%P;
	return num1%P;
}
bool ch(int x)
{
	int num=0;
	for(int i=1;i<=n;i++)
		if(c[i]<=f[i]+num)
			num++;
	if(num>=n-m) return 1;
	else return 0;
}
void dfs(int t)
{
	if(t>n)
	{
		if(ch(m)==1)
			num++;
	}	 
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{				
			vis[i]=1;
			c[t]=a[i];
			dfs(t+1);
			c[t]=0;
			vis[i]=0;
		}		
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i]=f[i-1];
		if(s[i-1]=='0')f[i]++;
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<num;
	return 0;
}
