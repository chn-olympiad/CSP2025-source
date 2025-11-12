#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],d1,e=0,f=-1;
bool d[500005];
void bobobo(int x,int y,int z)
{
	if(x>a)
	{
		d1=max(d1,y);
		return;
	}
	for(int i=x;i<=a;i++)
	{
		
		if(z==-1)
		{
			z=c[i];
			
		}
		else 
		{
			z=z^c[i];

		}
		if(z==b)
			{
				bobobo(i+1,y+1,-1);
				return;
			}
		if(d[i]!=0)
		{
			d[i]=1;
			bobobo(i+1,y,-1);
			d[i]=0;
		}
		
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	bobobo(1,0,-1);
	cout<<d1;
	return 0;
}
