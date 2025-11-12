#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[10001][6],sum=0,o[4],max,k,m2=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		
		
		sum=0;
		for(int u=0;u<3;u++)
			o[u]=0;
		for(int j=0;j<n;j++)
		{
			k=0;
			max=0;
			for(int z=0;z<3;z++)
			{
				cin>>a[j][z];
				if(a[j][z]>max)
				{
					max=a[j][z];
					k=z;
					//cout<<k<<endl;
				}
				
			}
			o[k]++;
				sum+=max;
			if(o[k]>n/2)
			{
				o[k]--;
				for(int h=0;h<3;h++)
				{
					if(a[j][h]>m2&&h!=k)
					{
						k=h;
						m2=a[j][h];
					}
					
					//cout<<k<<endl;
				}
				o[k]++;
				sum=sum-max+m2;
			}
				
			
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
