#include<bits/stdc++.h>
using namespace std;
long long m,n,i,j,s,c=1,r,a[100010],b,maxa;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[j];
		}
	}
	for(j=1;j<=m;j++)
	{
		r=1;
		maxa=0;
		for(i=1;i<=n;i++)
		{
			b=a[1];
			maxa=max(maxa,a[j]);
			if(maxa>b)
			{
				r++;
				if(r>n) r=1,c++;
			}
			else if(maxa<b)
			{
				continue;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
