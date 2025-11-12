#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,m,g,h;
int a[5000001],s;
int main()
{
	freopen("xor.in"."r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(k<=1)
	{
		if(k==0)
		{
			if(n<=2)
			{
				if(n==2)
				{
					cout<<1;
					return 0;
				}
				if(n==1)
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]==0)
						g++;
					if(a[i]==1&&a[i+1]==1)
					{
						h++;
						i++;
					}
				}
				cout<<h+g;
				return 0;
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]==1)
					h++;
			}
			cout<<h;
			return 0;
		}
	}
	else
	{
		for(l=0;l<n;l++)
		{
			for(r=l;r<n;r++)
			{
				m=a[r];
				for(int i=r+1;i<=l;i++)
				{
					if(a[i]==-1)
					    break;
					else m=m^a[i];
				}
				if(m==k)
				{
					s++;
					for(int i=r;i<=l;i++)
					{
						a[i]=-1;
					}
				}
			}
		}
		cout<<s;
	}
	return 0;
}
