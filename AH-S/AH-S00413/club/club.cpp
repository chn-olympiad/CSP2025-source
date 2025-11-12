#include<bits/stdc++.h>
using namespace std;
long long T,n,f[105],a[10005][4];
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.in","w",stdout);
  cin>>T;
  while(T--)
  {
	  long long c=0;
	  cin>>n;
	  for(int i=1;i<=n;i++)
	  {
		  for(int j=1;j<=3;j++)cin>>a[i][j];
	  }
	  if(n==2)
	  {
		  for(int i=1;i<=3;i++)
		  {
			  for(int j=1;j<=3;j++)
			  {
				  f[i]++;
				  f[j]++;
				  if(f[1]>n/2||f[2]>n/2||f[3]>n/2)
				  {
				  }
				  else c=max(c,a[1][i]+a[2][j]);
			  }
		  }
		  cout<<c<<'\n';
	  }
	  else if(n==4)
	  {
		   for(int i=1;i<=3;i++)
		  {
			  for(int j=1;j<=3;j++)
			  {
				  for(int p=1;p<=3;p++)
				  {
					  for(int q=1;q<=3;q++)
					  {
						  f[1]=0,f[2]=0,f[3]=0;
						  f[i]++;
						  f[j]++;
						  f[p]++,f[q]++;
						  if(f[1]>n/2||f[2]>n/2||f[3]>n/2)
						  {
						  }
						  else c=max(c,(a[1][i]+a[2][j]+a[3][p]+a[4][q]));
					  }
				  }
				  
			  }
		  }
		  cout<<c<<'\n';
	  }
	 
  }
}
//Ren5Jie4Di4Ling5%
