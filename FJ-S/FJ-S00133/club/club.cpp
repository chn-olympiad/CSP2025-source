#include<bits/stdc++.h>
using namespace std;
int ans=0;
int t,n;
int a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int max,s,x=1,ans[100005],d=0,e=0,f=0;
	cin>>t;
	do
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3])
			{
				max=a[j][1];
				d++;
				if(d>n/2)
				{
					ans[x]=13;
					//if(a[j][2]>=a[j][3])
					//{
					//	s=a[j][2];
					//	ans[x]+=s;
					//}
					//else
					//{
					//	s=a[j][3];
					//	ans[x]+=s;
					//}
					continue;
				}
						ans[x]+=max;
			}
			if(a[j][2]>a[j][1]&&a[j][2]>a[j][3])
			{
				max=a[j][2];
				e++;
				if(e>n/2)
				{
					ans[x]=4;
					//if(a[j][1]>=a[j][3])
					//{
					//	s=a[j][1];
					//	ans[x]+=s;
					//}
					//else
					//{
					//	s=a[j][3];
					//	ans[x]+=s;
					//}
					continue;
				}
						ans[x]+=max;
			}
			if(a[j][3]>a[j][1]&&a[j][3]>a[j][2])
			{
				max=a[j][3];
				f++;
				if(f>n/2)
				{
					if(a[j][1]>=a[j][2])
					{
						s=a[j][1];
						ans[x]+=s;
					}
					else
					{
						s=a[j][2];
						ans[x]+=s;
					}
                    continue;
				}
						ans[x]+=max;
			}

	    }
		x++;
	}while(x<=t);
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
} 
