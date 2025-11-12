#include<iostream>
#include<cstdio>
using namespace std;
int n,m,r,a[10001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
	  cin>>a[i];
	}
	r=a[1];
	int l=0;
	for(int i=2;i<=n*m;i++)
	 for(int j=2;j<=n*m;j++)
	  	if(a[j]>a[j-1])
	  	{
		  l=a[j-1];
		  a[j-1]=a[j];
		  a[j]=l;	
	    }
	for(int i=1;i<=m;i++)
	  if(i%2==1)
	  {
	    for(int j=1;j<=n;j++)
		  if(r==a[(i-1)*m+j])
		  {
		    cout<<i<<" "<<j;
		    return 0;
		  }
	  }
	  else
	    for(int j=n;j>0;j--)
	      if(r==a[i*m-j+1])
	      {
	        cout<<i<<" "<<j;
	        return 0;
		  }
	return 0;
}
 

