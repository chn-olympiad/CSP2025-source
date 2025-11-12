#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int a;
int x[100001];
int y[10001][10001];
int b=0;
int n[100001000][2],m,q;
int z[100001000][2],w;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>x[i];
	}
	sort(x,x+a);
	m=1;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			y[i][j]=x[i]+x[j];
			n[m][0]=y[i][j];
			n[m][1]=j;
			z[m][0]=y[i][j];
			z[m][1]=j;
			m=m+1;
		}
	}
	w=m;
	
	for(int l=3;l<=a;l++)
	{
		q=w-1;
		w=1;
		for(int p=1;p<=q;p++)
		{
			for(int i=1;i<=a;i++)
			{
				if(i>z[p][1])
				{
					n[w][0]=x[i]+z[p][0];
					n[w][1]=i;
					if(n[w][0]>2*x[i])
					{
						b=b+1;
					}
					w=w+1;
				}
			}
		}
		for(int i=1;i<=w-1;i++)
		{
			z[i][0]=n[i][0];
			z[i][1]=n[i][1];
		}
	}
	cout<<b%998244353;
	return 0;
}
