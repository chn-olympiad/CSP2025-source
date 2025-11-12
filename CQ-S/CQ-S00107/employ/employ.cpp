#include<iostream>
using namespace std;
	int n,m,sum=0;
	int a,d[1000];
	int b[1000],c[1000],flag[1000],sum1,sum0;
int a2(int a)
{if(a!=1)
	return ((a2(a-1)% 998244353)*(a% 998244353)% 998244353;
else
	return 1;
}
int main()
{
	freopen("employ.in ","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;

	cin>>a;
	for(int i=0;i<n;i++)
	{
		
		cin>>b[i];
	}
	int s=n;
	while(a)
	{
		c[s-1]=a%10;
		s--;
		a/=10;
	}
	sum=a2(n);
	cout<<sum;
}
