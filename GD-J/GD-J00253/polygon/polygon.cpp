#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long sum,n;
int a[5005];
//void solve(int m,int len)
//{
//	if(m==n+1)
//	{
//		sum++;
//		return;
//	}
//	int x=0;
//	for(int i=1;i<=len;i++)
//	{
//		for(int j=i;j<=len;j++)
//		{
//			x=x+a[i]+a[j];
//		}
//	}
//}
int main()
{
	freopen("stdin.polygon","r",stdin);
	freopen("stdout.polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			sum=1;
		}
	}
	cout<<sum%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
