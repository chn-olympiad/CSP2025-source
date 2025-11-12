#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int k[10000];
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int g=0;g<t;g++)
	{
	long long n,a[10000],b[10000],c[10000],a1=0,a2=0,a3=0,n1,n2,n3;
	cin>>n;
	n1=n/2;
	n2=n/2;
	n3=n/3;
	for(int i=0;i<n;i++)
	{
		cin>>a1>>a2>>a3;
		a[i]=a1;
		b[i]=a2;
		c[i]=a3;
	}
	sort(a,a+n,cmp);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(max(a[i],b[i])==a[i]&&max(a[i],c[i])==a[i])
		{
			if(n1!=0)
			{
				ans=ans+a[i];
				n1--;
			}
			else if(n1==0)
			{
				if(b[i]>c[i]&&n2!=0)
				{
						ans=ans+b[i];
						n2--;
				}
				else
					{
						ans=ans+c[i];
						n3--;
					}
			}
		}
		else if(max(a[i],b[i])==b[i]&&max(b[i],c[i])==b[i])
		{
			if(n2!=0)
			{
				ans=ans+b[i];
				n2--;
			}
			else if(n2==0)
			{
				if(a[i]>c[i]&&n1!=0)
				{
						ans=ans+a[i];
						n1--;
				}
				else
					{
						ans=ans+c[i];
						n3--;
					}
			}
		}
		else if(max(c[i],b[i])==c[i]&&max(a[i],c[i])==c[i])
		{
			if(n3!=0)
			{
				ans=ans+c[i];
				n3--;
			}
			else if(n3==0)
			{
				if(b[i]>a[i]&&n2!=0)
				{
						ans=ans+b[i];
						n2--;
				}
					else
					{
						ans=ans+a[i];
						n1--;
					}
			}
		}
		cout<<ans<<endl;
	}
	k[g]=ans;
	}
	for(int i=0;i<t;i++)
	{
		cout<<k[i]<<endl;
	}
	return 0;
}
