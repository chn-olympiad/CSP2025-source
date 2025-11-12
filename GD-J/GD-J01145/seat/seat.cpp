#include<bits/stdc++.h>
using namespace std;
int n,m,c[10005],e,f,g,h,a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>c[i];
	}
	g=c[0];
	for(int i=0;i<=10000000;i++)
	{
		if(c[i+1]>c[i])
		{
			e=c[i]; f=c[i+1];
			c[i]=f; c[i+1]=e;
		}
	}
	for(int i=0;i<=n*m-1;i++)
	{
		if(c[i]==g){h=i+1;}
	}
	if(h<=n)
	{
		cout<<1<<" "<<h;
	}
	else if(h==m*n&&m%2==0)
	{
		cout<<m<<" "<<1;
	}
	else if(h==m&&m%2==1)
	{
		cout<<m<<" "<<n;
	}
	else 
	{
		a=h;
	    a=a%n;
	    h=h/m+1;
	    if(h%2==0)
	    {
		    if(a==0){a=n;cout<<h-1<<" "<<a;}
		    else {cout<<h<<" "<<n-a+1;}
	    }
	    else
	    {
		    if(a==0){a=1;cout<<h-1<<" "<<a;}
		    else {cout<<h<<" "<<a;}
	    }
	}
	
	
	return 0;
}
