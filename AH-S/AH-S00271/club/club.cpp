#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x1,x2,x3,r;
}a[1000024];
int t;
bool cmp(node x,node y)
{
	return x.r>y.r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int w1=n/2,w2=n/2,w3=n/2;
		for(int i=0;i<n;i++)
		{
			a[i].x1=a[i].x2=a[i].x3=a[i].r;
		}
		for(int i=0;i<n;i++)
		{
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			int max1,max2;
			if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3)
			{
				max1=a[i].x1;
				if(a[i].x2>a[i].x3)
				{
					max2=a[i].x2;
				}
				else
				{
					max2=a[i].x3;
				}
			}
			else if(a[i].x2>=a[i].x1&&a[i].x2>=a[i].x3)
			{
				max1=a[i].x2;
				if(a[i].x1>a[i].x3)
				{
					max2=a[i].x1;
				}
				else
				{
					max2=a[i].x3;
				}
			}
			else
			{
				max1=a[i].x3;
				if(a[i].x1>a[i].x2)
				{
					max2=a[i].x1;
				}
				else
				{
					max2=a[i].x2;
				}
			}
			a[i].r=max1-max2;
		}
		sort(a,a+n,cmp);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			
			if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3)
			{
				if(w1)
				{
					ans+=a[i].x1;
					w1--;
				}
				else if(a[i].x2>a[i].x3)
				{
					ans+=a[i].x2;
					w2--;
				}
				else
				{
					ans+=a[i].x3;
					w3--;
				}
			}
			else if(a[i].x2>=a[i].x1&&a[i].x2>=a[i].x3)
			{
				if(w2)
				{
					ans+=a[i].x2;
					w2--;
				}
				else if(a[i].x1>a[i].x3)
				{
					ans+=a[i].x1;
					w1--;
				}
				else
				{
					ans+=a[i].x3;
					w3--;
				}
			}
			else
			{
				//cout<<1<<endl;
				if(w3)
				{
					ans+=a[i].x3;
					w3--;
				}
				else if(a[i].x1>a[i].x2)
				{
					ans+=a[i].x1;
					w1--;
				}
				else
				{
					ans+=a[i].x2;
					w2--;
				}
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
