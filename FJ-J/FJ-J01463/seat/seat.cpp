#include<iostream>
#include<cstdio>
using namespace std;
int a[10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,t=1;
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++)
	{
		cin>>y;
		if(y>x)t++;
	}
	int k1=t/n+1,k2=t%n;
	if(k2==0)k2=n,k1--;
	if(k1%2)cout<<k1<<' '<<k2;
	else cout<<k1<<' '<<n-k2+1;
	return 0;
}
