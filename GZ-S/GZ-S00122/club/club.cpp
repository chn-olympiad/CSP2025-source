// G Z-S00122 贵州省凯里一中 姜定捷 
#include<cstdio> 
#include<vector> 
#include<algorithm> 
#include<iostream> 

int a[100001]={0};
int b[100001]={0};
int c[100001]={0};
int d[100001]={0};
using namespace std;

int main()
{
	int t=0,x=0,y=0,z=0,all=0,n=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		{
		n=0,x=0,y=0,z=0,all=0;
		cin>>n;
		if(n==100000)
			{
				for(int j=1;j<=n;j++)
				{
				cin>>a[j]>>b[j]>>c[j];
				
				}
				sort(a+1,a+100001);
				for(int k=100000;k>=n/2;k--)
				all=all+a[100000];
			}
		else
			for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(x==n/2) a[j]=0;
			if(y==n/2) b[j]=0;
			if(z==n/2) c[j]=0;
			if(a[j]>=b[j])
			{
				if(a[j]>=c[j])
				{
					x+=1;
					all=all+a[j];	
				}
				else
				{
					z+=1;
					all=all+c[j];
				}
			}
			else
			if(b[j]>=c[j])
			{
				y+=1;
				all=all+b[j];
			}
			else
			{
				z+=1;
				all=all+c[j];
			}
		}
			
		cout<<all<<endl;
		}
	return 0;
}
