#include<iostream>
#include<cstdio>
#include<algorithm>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,m,ans=0;
int a[101];
int c=1,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	r=n*m;
	int d;
	for(int i=0;i<=n*m;i++)
	{
			cin>>a[i];
		if(a[1]==100)
		{
			cout<<c<<" "<<r;
			sort(a+1,a+i+1);
		}
		if(a[i]!=a[1])
		{
			d++;
		}
			if(d>n)
			{
				d=d-n;
				r++;
			}
	}
	cout<<c<<" "<<r;
	return 0;
}
