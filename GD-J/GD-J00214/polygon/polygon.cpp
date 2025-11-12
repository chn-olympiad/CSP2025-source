#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
int n,a[10000],sum;
bool cmp(int i,int j)
{
	return i<j;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	/*for(int i=1;i<=n;i++)
	 cout<<a[i]<<" ";*/
	if(n==3) 
	{
		if(a[1]+a[2]>a[3])
			sum++;
	}
	cout<<sum;
	return 0;
}
