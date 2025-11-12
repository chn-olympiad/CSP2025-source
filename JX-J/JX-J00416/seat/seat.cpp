#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,R,Rs,x,y,l,lw=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}  
	R=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==R) 
		{
			Rs=lw;
			break;
		}
		lw++;
	}
	l=Rs%n;
	//cout<<Rs;
	if(l>0)
	{
		x=Rs/n+1;
	    y=(Rs-1)%n+1;
	    if(x%2==0)
	    {
			cout<<x<<" "<<n-y+1; 
		} 
	    else 
	    {
			cout<<x;
			cout<<" ";
			cout<<y;
		}
	}
	else
	{
		x=Rs/n;
	    y=(Rs-1)%n+1;
	    if(x%2==0) 
	    {
			cout<<x<<" "<<n-y+1; 
		}
	    else 
	    {
			cout<<x;
			cout<<" ";
			cout<<y;
		}
	}
	return 0;
}
