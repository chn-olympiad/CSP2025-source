#include <bits/stdc++.h>
using namespace std;
int n,m,k,minn=0; 
int u[10005],v[10005],w[10005],c[15],a[15][10005];
int main()
{
	freopen("road.in ","r",stdin);
	freopen("road.out ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m,i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	int k1=k;
	while(k1!=0)
	{
		for(int i=1;i<=m;i++)
		{
			int a=min(w[i],w[i+1]);
			if(a==w[i])
			{
				w[i]=w[i+1];
			}
			else
			{
				w[i+1]=w[i];
			}
	    }
	    k1-=1;
	    minn+=a;
	}
	
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	while(k!=0)
	{
		for(int j=1;j<=k;j++)
	    {
		    int c=min(c[j],c[j+1]);
		    if(c=c[j])
			    {
				   c[j]=c[j+1];
			    }
			    else
			    {
				    c[j+1]=c[j];
			    }
		    for(int i=1;i<=n;i++)
		    {
			    int b=min(a[j][i],a[j][i+1]);
			    if(b==a[j][i])
			    {
				   a[j][i]==a[j][i+1];
			    }
			    else
			    {
				    a[j][i+1]==a[j][i];
			    }
		    }
	    }
	    k-=1;
	    int sum=b+c;
	}
	int num=sum+minn;
	cout<<num;
}
