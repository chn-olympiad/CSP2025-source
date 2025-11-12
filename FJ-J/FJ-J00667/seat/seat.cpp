#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],b,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			b++;
		}
	}
	b++;
	if(b%n==0)
	{
		l=b/n;
	}else{
		l=b/n+1;
	}
	if(b%(2*n)>n)
	{
		h=n-b%(2*n)+1;
	}else{
		h=b%(2*n);
	}
	cout<<l<<" "<<h;
	return 0;
}