#include<bits/stdc++.h>
using namespace std;
#define N 50005
long long a[N],n,d[N],cnt;
long long fun(int x,int y)
{
	long long max=-1;
	for(int b=x;b<=y;b++)
	{
	if(a[b]>max)max=a[b];
	}
	return max;
}
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	d[i]=d[i-1]+a[i];
}
for(int i=1;i<=n;i++)
{
	for(int j=i+2;j<=n;j++)
	{
		if(fun(i,j)*2<d[j]-d[i-1])
		{
		cnt++;
		cnt%=998244353;
		}
	}
}
cout<<cnt<<endl;
return 0;
}
