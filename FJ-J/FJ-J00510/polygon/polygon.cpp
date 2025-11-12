#include<bits/stdc++.h>
using namespace std;
int a,b,c[111111],d,e[11111],f,maxx,z,g,h;
string s;
void man(int m)
{
    for(int i=1;i<=a;i++)
	{
//		for(int j=i;j<=a;j++)
//		{
//			if(e[i]>0)
//			{
//				h=1;
//			}
//		}
		if(e[i]==0)
		{
		   e[i]=c[i];
		   //e[i]=0;	
		   man(m+1);
		   e[i]=0;
		   //m=m-1;	
		}
		h=0;
	}
	if(m>=3&&m<=a)
	{
		for(int i=1;i<=m;i++)
		{
			maxx=max(maxx,e[i]);
			z=z+e[i];
		} 
		if(z>2*maxx)
		{
			f++;
//			for(int i=1;i<=m;i++)
//			{
//				cout<<e[i]<<" ";
//			}
//			cout<<endl;
		}
		maxx=0;
		z=0;
		for(int i=1;i<=m;i++)
		{
			e[i]=0;
		}
	}
}
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	man(0);
	if(a==3)
	{
		for(int i=1;i<=3;i++)
		{
			maxx=max(maxx,c[i]);
			z=z+c[i];
		}
		if(z>2*maxx)
		{
			cout<<1;
		}
		else cout<<0;
	}
	cout<<f%988244353;
	return 0;
} 
