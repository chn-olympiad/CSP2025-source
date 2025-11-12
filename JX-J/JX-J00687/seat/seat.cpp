#include<bits/stdc++.h>
using namespace std;
int a[102],b[102];
int n,m,n1,n2;
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
				//cout<<b[i]<<" ";
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[i]==b[j])
			{
				n1=ceil(j*1.0/(n*1.0));
				if(n1==1)
				{
					n2=j;
					cout<<n1<<" "<<n2;
					return 0;
				}
				else
				{
					if(n1%2==0)
					{
						n2=n-j+(n1-1)*n+1;
						cout<<n1<<" "<<n2;
						return 0;
					}
					else
					{
						n2=j-(n1-1)*n;
						cout<<n1<<" "<<n2;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
