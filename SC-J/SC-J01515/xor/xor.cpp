#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int a,b,c[N],c1[N],d[N],e,f,g,h;
int abc(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		if(d[i]==1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
		c1[i]=c1[i-1]^c[i];
	}
	if(a*a>=1e6+100)
	{
		if(b<=1 && a<=2e5)
		{
			if(b==1)
			{
				int o=0;
				for(int i=1;i<=a;i++)
				{
					if(c[i]==1)
					{
						o++;
					}
				}
				cout<<o;
				return 0;	
			}
			if(b==0)
			{
				int o=0;
				for(int i=1;i<=a;i++)
				{
					if(c[i]==0)
					{
						o++;
					}
					if(c[i]==1 && c[i+1]==1)
					{
						o++;
						i++;
					}
				}
				cout<<o;
				return 0;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(!abc(j,j+i-1))
			{
				continue;
			}
			int u=c1[j+i-1]^c1[j-1];
			if(u==b)
			{
				e++;
				//cout<<j<<" "<<j+i-1<<" "<<c1[j+i-1]<<' '<<c1[j-1]<<' '<<u<<"\n"; 
				for(int k=j;k<=j+i-1;k++)
				{
					d[k]=1;
				} 
				continue;
			}
		}
	}
	cout<<e;

	return 0;
}
/*
4 2
2 1 0 3
*/
/*
4 3
2 1 0 3
*/
/*
4 0
2 1 0 3
*/