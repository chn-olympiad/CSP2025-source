#include<bits/stdc++.h>
using namespace std;
long long n,m,t,tw,a[10005],jsq;
bool cmp(const long long &a,const long long &b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i+=2)
	{
		for(int j=1;j<=n;j++)
			if(a[++jsq]==t)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		for(int j=n;j>=1;j--)
			if(a[++jsq]==t)
			{
				cout<<i+1<<' '<<j;
				return 0;
			}
	}
	return 0;
}
