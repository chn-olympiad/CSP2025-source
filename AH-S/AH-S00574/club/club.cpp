#include<bits/stdc++.h>
using namespace std;
	int idmax[201],idmid[201],idmin[201];
	int a[201][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	int flag[t+1];
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		int ans=0;
		int id[4]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]<=a[i][2]&&a[i][2]<=a[i][3]){idmax[i]=3;idmid[i]=2;idmin[i]=1;}
			else if(a[i][1]<=a[i][3]&&a[i][3]<=a[i][2]){idmax[i]=2;idmid[i]=3;idmin[i]=1;}
			else if(a[i][2]<=a[i][3]&&a[i][3]<=a[i][1]){idmax[i]=1;idmid[i]=3;idmin[i]=2;}
			else if(a[i][2]<=a[i][1]&&a[i][1]<=a[i][3]){idmax[i]=3;idmid[i]=1;idmin[i]=2;}
			else if(a[i][3]<=a[i][2]&&a[i][2]<=a[i][1]){idmax[i]=1;idmid[i]=2;idmin[i]=3;}
			else if(a[i][3]<=a[i][1]&&a[i][1]<=a[i][2]){idmax[i]=2;idmid[i]=1;idmin[i]=3;}
			id[idmax[i]]++;
			ans+=a[i][idmax[i]];
		}
		
		if(id[1]>n/2)
		{
			int f=0,c[201];
			for(int i=1;i<=n;i++)
			{
				if(a[i][1]==a[i][idmax[i]])
				{
					f++;
					c[f]=a[i][idmid[i]]-a[i][1];
				}
			}
			for(int i=1;i<=f;i++)
			{
				for(int j=i+1;j<=f;j++)
				{
					if(c[i]<c[j]){int v=c[i];c[i]=c[j];c[j]=v;}
				}
			}
			for(int i=1;i<=id[1]-n/2;i++)
			{
				ans+=c[i];
			}
		}
		
		if(id[2]>n/2)
		{
			int f=0,c[201];
			for(int i=1;i<=n;i++)
			{
				if(a[i][2]==a[i][idmax[i]])
				{
					f++;
					c[f]=a[i][idmid[i]]-a[i][2];
				}
			}
			for(int i=1;i<=f;i++)
			{
				for(int j=i+1;j<=f;j++)
				{
					if(c[i]<c[j]){int v=c[i];c[i]=c[j];c[j]=v;}
				}
			}
			for(int i=1;i<=id[2]-n/2;i++)
			{
				ans+=c[i];
			}
		}
		
		if(id[3]>n/2)
		{
			int f=0,c[201];
			for(int i=1;i<=n;i++)
			{
				if(a[i][3]==a[i][idmax[i]])
				{
					f++;
					c[f]=a[i][idmid[i]]-a[i][3];
				}
			}
			for(int i=1;i<=f;i++)
			{
				for(int j=i+1;j<=f;j++)
				{
					if(c[i]<c[j]){int v=c[i];c[i]=c[j];c[j]=v;}
				}
			}
			for(int i=1;i<=id[3]-n/2;i++)
			{
				ans+=c[i];
			}
		}
		flag[k]=ans;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<flag[i]<<endl;
	}
	return 0;
}
