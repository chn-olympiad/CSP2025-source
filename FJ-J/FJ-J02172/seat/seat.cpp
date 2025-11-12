#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10010],k;
bool abc(long long w,long long e)
{
	return w>e;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,abc); 
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			k=i;
			break;
		}
	}
    long long x,y,z;
    x=k/n;
    z=k%n;
    if(z!=0)
      x++;
    if(x%2==0)
    {
    	if(z==0)
    	  y=1;
    	else
    	 y=n-z+1;
	}
    else
    {
		y=z;
		if(z==0)
		y=n;
	}
    cout<<x<<" "<<y;
    return 0;
}
