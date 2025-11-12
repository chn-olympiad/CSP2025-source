#include<bits/stdc++.h>
using namespace std;
int t,n,maxn[1000000]; 
int a[300005],b[300005],c[300005],best[300005],sum;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  while(t--)
    {
      cin>>n;
      sum=0;
      for(int i=1;i<=n;i++)
        {
        	cin>>a[i]>>b[i]>>c[i];
        	if(a[i]>=b[i]&&a[i]>=c[i])
        	  maxn[i]=a[i];
        	if(b[i]>=a[i]&&b[i]>=c[i])
        	  maxn[i]=b[i];
			if(c[i]>=a[i]&&c[i]>=b[i])
        	  maxn[i]=c[i];					
		}
	  for(int i=1;i<=n;i++)
	    sum+=maxn[i];
	  cout<<sum;
	}
  return 0;	
} 
