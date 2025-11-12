#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat,out","w",stdout);
    int n,m,l,b,c=1,d=1;
    bool e=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	b=a[1];
	for(int i=1;i<=n*m;i++)
	 for(int j=1;j<n*m;j++)
	 {
	 	if(a[j]<a[j+1])
	 	{
	 		l=a[j];
	 		a[j]=a[j+1];
	 		a[j+1]=l;
		 }
	 }
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]!=b)
		{
			if(e==1)
			  d=d+1;
			if(e==0)
			  d=d-1;
		}
		if(d==n+1)
		{
			d=n;
			e=0;
			c=c+1;
		}
		if(d==0)
		{
			d=1;
			e=1;
			c=c+1;
		}
		if(a[i]==b)
		{
			cout<<c<<" "<<d;
			break;
		}
	}
	return 0;
}