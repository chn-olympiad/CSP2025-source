#include<bits/stdc++.h>
using namespace std;
long long a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,h=0;
	int r=0,c=0;
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>r)
		{
			h++;
		}
	}
	h++;
	int z=h;
	if(h%n==0) c=h/n;
	else c=h/n+1;
	if(c%2!=0)
	{
		r=h%n;
		if(r==0) r=n;
	}
	else
	{
		r=n-(h-n)%(2*n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
