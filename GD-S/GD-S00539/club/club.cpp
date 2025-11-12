#include<iostream>
#include<cstdio>


using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[20010],b[20010],c[20010],ans[20010],ca[20010],finans[20010];
	
	
	int t,n,m1,m2,m3,maxm;
	m1=0,m2=0,m3=0;
	cin>>t>>n;
	for(int j=1;j<=t;j++)
	{
			for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		while(m1<=(n/2)&&m2<=(n/2)&&m3<=(n/2))   
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]<b[i])
				{
					maxm=b[i];
				if(maxm<c[i])
				{
					maxm=c[i];
				}
				
			}
			else if(a[i]>b[i])
			{
				maxm=a[i];
				if(maxm<c[i])
				{
					maxm=c[i];
				}
			}
			else 
			{
				maxm=a[i];
				if(maxm<c[i])
				{
					maxm=c[i];
				}
			}
			ca[i]=maxm;
		}
		for(int i=1;i<=n;i++)
		{
			ans[j]=ca[i]+ans[j]; 
		}
		break;
	}
	}
	for(int j=1;j<=t;j++)
	{
		cout<<ans[j]<<endl;
	}
	
	
	
	return 0;
}
