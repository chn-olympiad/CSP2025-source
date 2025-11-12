#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m;
const long long M=998244353;
long long pow(int x,int y)
{
	long long sum=1;
	while(y)
	{
		if(y&1)
		{
			sum*=x;
		}
		y>>=1;
		x=x*x%M;
	}
	return sum; 
} 
long long dfs(int x,int sum)
{
	if(m*2<sum)return pow(2,n-x+1)%M;
	if(x>n)
	{
		if(m*2<sum)return 1;
		else return 0;
	}
	int sadbee=0,cmp=m;
	//ัก
	m=max(m,a[x]);
	sadbee+=dfs(x+1,sum+a[x]);
	m=cmp;
	//ฒปัก 
	sadbee+=dfs(x+1,sum);
	
	
	return sadbee%M;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	long long ans=dfs(1,0);
	printf("%lld",ans);
	return 0;
}
