#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,d;
	int s=0;
	cin>>n>>m>>a;
	int b=n*m-1;
	for(int i=1;i<=b;i++)
	{
		cin>>d;
		if(d>a)s++;
	}
	int c=0,r=0;
	if(s>=n)c=s/n+1;
	if(s<n)c=1;
	int v=s%n;
	if(c%2==0)r=n-v;
	if(c%2==1)r=v+1;
	cout<<c<<' '<<r;
	return 0;
}
