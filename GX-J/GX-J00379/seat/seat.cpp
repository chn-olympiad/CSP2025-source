#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[10010];
int main()
{
  	freopen("seat.in","r",stdin);
  	freopen("seat.out","w",stdout);
  	cin>>n>>m;
  	for(int i=1;i<=n*m;i++)
  	{
	  	cin>>a[i];
	  	if(a[i]>a[1]) k++;
	}
    k++;
    int val=0;
    for(int i=1;i<=n;i++)
    {
      if(i%2!=0) 
      {
	    for(int j=1;j<=m;j++)
	    {
		  val++;
		  if(val==k)
		  {
			cout<<i<<" "<<j;
			return 0;  
		  }
	    }
      }
      else if(i%2==0)
      {
		   for(int j=m;j>=1;j--)
		   {
			  val++;
			  if(val==k)
			  {
				cout<<i<<" "<<j;
				return 0;  
			  }   
		   }
	  }	
	}
  	return 0;
}
