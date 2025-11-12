#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100007],b[100007],c[100007];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==2)
		{
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			int sum[6];
			sum[0]=a+e;
			sum[1]=a+f;
			sum[2]=b+d;
			sum[3]=b+f;
			sum[4]=c+d;
			sum[5]=c+e;
			sort(sum,sum+6);
			cout<<sum[5]<<endl;
		}
		
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
				
				
			}
			
			
				sort(a+1,a+n+1);
				int ans=0;
				for(int i=n;i>n/2;i--)
				{
					ans+=a[i];
				}
				
				cout<<ans<<endl;
			
			
		}
		
	}
	
	return 0;
}
