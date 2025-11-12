#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],c,v;
	cin>>n>>m;
	for(v=1;v<=n*m;v++)
		cin>>a[v];
	c=a[1];
	for(int i=1;i<=n*m;i++)
		for(int i=1;i<n*m;i++)
			if(a[i]<a[i+1])
				swap(a[i],a[i+1]);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<a[1]<<" ";
				if(a[1]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				
				a[1]=1;
				for(int i=1;i<=n*m;i++)
					for(int i=1;i<n*m;i++)
						if(a[i]<a[i+1])
							swap(a[i],a[i+1]);
			}
		}
		else if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				cout<<a[1]<<endl;
				if(a[1]==c)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				a[1]=1;
				for(int i=1;i<=n*m;i++)
					for(int i=1;i<n*m;i++)
						if(a[i]<a[i+1])
							swap(a[i],a[i+1]);
			}
		}
	}
	return 0;
}
