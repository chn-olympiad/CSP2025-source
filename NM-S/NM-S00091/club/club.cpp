#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3];
int ren1[10010];
bool f[1000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	    {
	    	cin>>n;
	    	int ans=0; 
	    	for(int i=1;i<=n;i++)
	    	     {cin>>a[i][1]>>a[i][2]>>a[i][3];
				 }
			for(int i=1;i<=n;i++)
			   {
				if(a[i][2]==0&&a[i][3]==0) 
				    { for(int j=1;j<=n;j++)if(a[j][1]<a[j+1][1]) swap(a[j][1],a[j+1][1]);
				       for(int j=1;j<=n/2;j++)
				           ans+=a[j][1];
				         cout<<ans<<endl;
					 }
				else if(a[i][3]==0)  
				    {
					  for(int j=1;j<=n;j++)if(a[j][1]<a[j+1][1]) swap(a[j][1],a[j+1][1]);
				      for(int j=1;j<=n;j++)if(a[j][2]<a[j+1][2]) swap(a[j][2],a[j+1][2]);
				      for(int j=1;j<=n/2;j++)
				          ans+=a[j][2]+a[j][1];
						  cout<<ans<<endl;}
				    else {
					for(int j=1;j<=n;j++)if(a[j][1]<a[j+1][1]) swap(a[j][1],a[j+1][1]);
				      for(int j=1;j<=n;j++)if(a[j][2]<a[j+1][2]) swap(a[j][2],a[j+1][2]);
				      for(int j=1;j<=n;j++)if(a[j][3]<a[j+1][3]) swap(a[j][3],a[j+1][3]);
				      for(int j=1;j<=n/2;j++)
				          ans+=a[j][2]+a[j][1]+a[j][3];
					  }
					 } 
			cout<<ans<<endl;
		    } 
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
