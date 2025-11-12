#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001],m,n,b[10000001],cnt,flag;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>b[i];
	flag=b[0];
	sort(b,b+m*n,cmp);
	for(int i=1;i<=m;i++)
		if(i%2==0)
		{
		for(int j=n;j>=1;j--)
			if(b[cnt++]==flag)
				cout<<i<<" "<<j;
		}
		else
		{
		for(int j=1;j<=n;j++)
			if(b[cnt++]==flag)
				cout<<i<<" "<<j;
			}
	return 0;
}
