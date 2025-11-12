#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10001],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];	
    }
    int l=a[1];
    for(int i=2;i<=n;i++)
	 for(int j=2;j<=n;j++)
	  	if(a[j]>a[j-1])
	  	{
		  l=a[j-1];
		  a[j-1]=a[j];
		  a[j]=l;	
	    }
	for(int i=3;i<=n;i++)
	  for(int j=1;j<=n-i;j++) 
	    for(int x=i-1;x<=n-i+1;x++)
	      for(int y=i;y<=n;y++)
	      {
			if(a[j]+a[x]+a[y]>2*a[j])
			  ans++;  
		  }
    cout<<ans; 
	return 0;
}
 
