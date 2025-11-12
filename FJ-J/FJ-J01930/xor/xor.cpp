#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500000],is[500000];
bool fl;
int main()
{
	freopen("seat.in","r",cin);
	freopen("seat.out","w",cout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fl=1;
			int h=a[i];
			for(int k2=i+1;k2<=j;k2++)
			{
				h^=a[k2];
			}
			if(h=k)
			{
				for(int k2=i;k2<j;k2++)
				{
					if(is[k2])fl=0;
				}
				if(fl)
				{
					m++;
					for(int k2=i;k2<=j;k2++)is[k2]=1;
				}
			}
		}
	}
	cout<<m;
}
