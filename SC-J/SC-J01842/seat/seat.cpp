#include <bits/stdc++.h>
using namespace std;
int as[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>as[i];
	}
	int r=as[1];
	for(int i=1;i<n*m;i++)
	{   
	    int k=i;
		for(int j=i+1;j<=n*m;j++)
		{
			if(as[j]>as[k])
			k=j;
		}
		swap(as[i],as[k]);
	}
	for(int i=1;i<=n*m;i++)
	{
		  if(as[i]==r)
		  {
		  	  if(i%int(m)==0)
		  	  cout<<ceil(i/m)<<" "<<"1";
		  	else  if(int(ceil(i/m))%2==1)
		   {
			  cout<<ceil(i/m)<<" "<<i%int(m);
		    }else
		      cout<<ceil(i/m)<<" "<<(m-i%int(m))+1;
		      return 0;
		    }
	}
}