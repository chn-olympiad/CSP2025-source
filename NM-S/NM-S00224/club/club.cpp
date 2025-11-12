#include<bits/stdc++.h>
using namespace std;
int a[5];
int minn=1e9;
int m,o,p,q,t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		cin>>n;
		m=n/2;
		o=0;
		p=0;
		q=0;
		minn=1e9;

		for(int j=1;j<=n;j++)
		{
			cin>>a[1]>>a[2]>>a[3];
			if((a[1]>a[2]&&a[1]>a[3])&&(o+1)<=m)
			{
				ans+=a[1];
				o++; 
				continue;
			}
			else if((a[2]>a[1]&&a[2]>a[3])&&(p+1)<=m)
				 {
					ans+=a[2];
					p++;
					continue;
				 }
				 else if((a[3]>a[1]&&a[3]>a[2])&&(q+1)<=m)
					  {
							ans+=a[3];
							q++;
							continue;
				      }
				      else if((a[1]>a[2]&&a[2]>a[3])&&((o+1)>m&&(p+1)<=m))
						   {
								ans+=a[2];
								p++;
								continue;
						   }
						   else if((a[3]>a[2]&&a[2]>a[1])&&((q+1)>m&&(p+1)<=m))
								{
									ans+=a[2];
									p++;
									continue;
								}
								else if((a[3]>a[1]&&a[1]>a[2])&&((q+1)>m&&(o+1)<=m))
									 {
											ans+=a[1];
											o++;
											continue;
									  }
									  else if((a[2]>a[1]&&a[1]>a[3])&&((p+1)>m&&(o+1)<=m))
											{
												ans+=a[1];
												o++;
												continue;
											}
											else if((a[2]>a[3]&&a[3]>a[1])&&((p+1)>m&&(q+1)<=m))
												 {
														ans+=a[3];
														q++;
														continue;
												 }
												 else if((a[1]>a[3]&&a[3]>a[2])&&((o+1)>m&&(q+1)<=m))
													  {
															ans+=a[3];
															q++;
															continue;
													  }
													  else
													  {
															minn=min(a[1],min(a[2],a[3]));
															ans+=minn;
															if(minn==a[1]) o++;
															else if(minn==a[2]) p++;
															     else if(minn==a[3]) q++;
													  }
												  
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
