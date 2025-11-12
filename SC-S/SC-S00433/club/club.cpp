#include<bits/stdc++.h>
using namespace std;
int t,n;
int a1,a2,a3;
int c[100005]={};
int v[300005]={},f[300005]={},p[300005]={};
int b1=0,b2=0,b3=0;
int n1=0,n2=0,n3=0;
int ans=0;
	void d(int h,int m)
	{
		if(n1>n/2||n2>n/2||n3>n/2)
		{
			return ;
		}
		if(h==n*3+1)
		{
			ans=max(ans,m);	
			return ;
		}
		for(int i=1;i<=2;i++)
		{
			if(i==1)
			{
				if(p[f[h]]==0)
				{
					if(c[h]==1)
					{
						n1++;
						p[f[h]]=1;
						d(h+1,m+v[h]);
						p[f[h]]=0;
						n1--;
					}
					if(c[h]==2)
					{
						n2++;
						p[f[h]]=1;
						d(h+1,m+v[h]);
						p[f[h]]=0;
						n2--;
					}
					if(c[h]==3)
					{
						n3++;
						p[f[h]]=1;
						d(h+1,m+v[h]);
						p[f[h]]=0;
						n3--;
					}
				}
			}else
			{
				d(h+1,m);
			}
		}
		
		
	}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int g=1;g<=t;g++)
	{
		ans=0;
		cin>>n;
		int k=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			f[k]=i;
			v[k]=a1;
			c[k]=1;
			k++;
			f[k]=i;
			v[k]=a2;
			c[k]=2;
			k++;
			f[k]=i;
			v[k]=a3;
			c[k]=3;
			k++;
		}
		for(int i=1;i<=n*3;i++)
		{
			for(int j=1;j<=n*3-i;j++)
			{
				if(v[j]<v[j+1])
				{
					int e=v[j];
					v[j]=v[j+1];
					v[j+1]=e;
					e=f[j];
					f[j]=f[j+1];
					f[j+1]=e;
					e=c[j];
					c[j]=c[j+1];
					c[j+1]=e;
				}
			}
		}
		d(1,0);
		cout<<ans<<endl;
	}
	return 0; 
}