#include<bits/stdc++.h>//
using namespace std;
long long a[110][110],x[11000],y=0,n,m,c,v=1;
int main()
{
	peropen("number.in","r",stdin);
	peropen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>x[i];
		c=x[1];
	}
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=v;j<=n*m;j++)
			{
				y=max(y,x[j]);
				y=x[v];
			} 
			v++;
			if(m%2==0)
			{
				for(int q=n;q>=1;q--)
				{
					a[i][q]=y;
					if(a[i][q]==c)
					{
						cout<<i<<q<<endl;
						return 0;
					} 
				}
			}
			else 
			{
				a[i][k]=y;
				if(a[i][k]==c)
				{
					cout<<i<<" "<<k<<endl;
				    return 0;
				}
			}
		}
	}
	return 0;
}
