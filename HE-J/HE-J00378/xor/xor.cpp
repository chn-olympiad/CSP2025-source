#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,k,sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int c=0,d=0,e=0,v=0;
	cin>>n>>k;
	string g[n+3],q[n+3];
	int a[n+3]={0},b[n+3]={0};
	for(int i=1;i<=n;i++)
	{
		d=0;
		cin>>a[i];
		c=a[i];
		while(c)
		{
			g[i][d]=c%2;
			c=c/2;
			d++;
		}
	}
	q[1]=g[1];
	for(int i=1;i<=n-1;i++)
		for(int j=0;j<4;j++)
		{
			if(q[i][j]==g[i+1][j])
			  q[i+1][j]=0;
			else q[i+1][j]=1;
		}
	e=4;
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++)
		{
			while(e--)
			{
				b[i]=b[i]+q[i][j]*pow(2,j);
				if(b[i]==k)sum++;
			}
			e=4;
		}

	/*for(int i=1;i<=n;i++)
	{
		int p=0;v=0;
		for(int j=1;j<=n;j++)
	    {
	    	p=i;
	  		while(p<=j)
	  		{
	  			v=v+b[p];
	  			if(v==k)sum++;
	  			p++;
			}
	    }
	}*/
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
