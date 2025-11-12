#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005],f[100005]={0};
long long a1[100005],b1[100005],c1[100005];
bool cmp(int a,int b)
{
	if(a>b)return true;
	else return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	long long n;
	for(int j=0;j<t;j++)
	{
		cin>>n;
		int ans=0;
	    for(int i=0;i<n;i++)
    	{
    		cin>>a[i]>>b[i]>>c[i];
    		long long maxi=(max(c[i],(max(a[i],b[i]))));
    		int cnta=0,cntb=0,cntc=0;
    		if(maxi==a[i])
    		{
    			cnta++;
    			if(cnta<=n/2)
    			{
    				ans+=maxi;
				}
				else
				{
					maxi=max(b[i],c[i]);
					if(maxi==b[i])
					{
						cntb++;
						if(cntb<=n/2)
						{
							ans+=b[i];
						}
						else
						{
							ans+=c[i];
						}
					}
				}
			}
    	}
    	//long long maxi=(max(c[i],(max(a[i],b[i]))));
//    	for(int i=0;i<=n;i++)
//    	{
//    		a1[i]=a[i];
//    		b1[i]=b[i];
//    		c1[i]=c[i];
//		}
//		sort(a,a+n,cmp);
//		sort(b,b+n,cmp);
//		sort(c,c+n,cmp);
//		long long ans=0;
//		for(int i=0;i<=n/2;i++)
//		{
//			for(int j=0;j<=n/2;j++)
//			{
//				if(a[i]==a1[j])
//				{
//					f[j]=1;
//				}
//			}
//		}
//		for(int i=0;i<=n/2;i++)
//		{
//			if(f[i]==1)
//			{
//				ans+=a1[i];
//				f[i]=2;
//			}
//		}
//		for(int i=0;i<=n/2;i++)
//		{
//			for(int j=0;j<=n/2;j++)
//			{
//				if(b[i]==b1[j]&&f[j]==0)
//				{
//					f[j]=1;
//				}
//			}
//		}
//		for(int i=0;i<=n/2;i++)
//		{
//			if(f[i]==1)
//			{
//				ans+=b1[i];
//				f[i]==2;
//			}
//			
//		}
//		for(int i=0;i<=n/2;i++)
//		{
//			for(int j=0;j<=n/2;j++)
//			{
//				if(c[i]==c1[j]&&f[j]==0)
//				{
//					f[j]=1;
//				}
//			}
//		}
//		for(int i=0;i<=n/2;i++)
//		{
//			if(f[i]==1)
//			{
//				ans+=c1[i];
//			}
//		}
		cout<<ans<<endl;
	}
	return 0;
}
