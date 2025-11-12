#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int sum=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int arg=0;
	int n;
	long long a[N],b[N],c[N];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		int mana=0;
		int manb=0;
		int manc=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{	
			arg=n/2;
			cin>>a[j]>>b[j]>>c[j];
			long long maxn[j],minn[j];
			maxn[j]=max(a[j],b[j]);
			minn[j]=min(a[j],b[j]);
			int  midn[N];
			maxn[j]=max(maxn[j],c[j]);
			midn[j]=max(min(a[j],b[j]),c[j]);
			minn[j]=min(minn[j],c[j]);
			if(maxn[j]==a[j])
			{
				mana++;
				ans+=maxn[j];
				sum=ans;
			}
			else if(maxn[j]==b[j])
			{
				manb++;
				ans+=maxn[j];
				sum=ans;
			}
			else if(maxn[j]==c[j])
			{
				manc++;
				ans+=maxn[j];
				sum=ans;
			}
			
			//完美型 
			
			if(mana>arg)//当a超人数时 
			{
				for(int k=1;k<=j-1;k++)
				{
					if(maxn[j]>maxn[k])
					{
						ans-=maxn[k];
						manb--; 
					}
					
					else if(midn[j]==b[j])
					{
						manb++;
						ans=ans+c[j];
						sum=ans;
					}
					else if(midn[j]==c[j])
					{
						manc++;
						ans=ans+c[j];
						sum=ans;
					}
				} 
				/*cout<<ans<<endl;
				break;*/
			}
			else if(manb>arg)
			{
				for(int k=1;k<=j-1;k++)
				{
					if(maxn[j]>maxn[k])
					{
						ans-=maxn[k];
						manb--; 
					}
					if(midn[j]==a[j])
					{
						mana++;
						ans=ans+a[j];
						sum=ans;
					}
					else
					{
						manc++;
						ans=ans+c[j];
						sum=ans;
					}
						 
				}
				/*cout<<ans<<endl;
				break;*/
				
			}
			else if(manc>arg)
			{
				for(int k=1;k<=j-1;k++)
				{
					if(maxn[j]>maxn[k])
					{
						ans-=maxn[k];
						mana--; 
					}
					if(midn[j]==a[j])
					{
						mana++;
						ans=ans+a[j];
						sum=ans;
					}
					else
					{
						manb++;
						ans=ans+b[j];
						sum=ans;
					}	 	
				}
				/*cout<<ans<<endl;
				break;*/
			}
			
		}cout<<sum<<" ";
	}
	return 0;
} 
