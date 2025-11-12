#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[100000]={' '};
char h[100010]={' '};
int a=0,b,x,M,l,ps,g=0;
signed main()
{ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=100000;i++)
	{
		if(s[i]==' ')
		{
			x=i-1;
		}
	}
	for(int i=0;i<x;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			h[g]=s[i];
			g++;
			a+=1;
		}
	}
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=a;j++)
		{
			ps=0;
			if(h[j]>h[j+1]&&j+1<=a)
			{
				continue;
			}
			if(h[j]==h[j+1]&&j+1<=a)
			{
				continue;
			}
			if(h[j]==h[j+1]&&j+1==a)
			{
				continue;
			}
			if(h[j]<h[j+1]&&j+1<=a)
			{
				l=h[j];
				h[j]=h[j+1];
				h[j+i]=l;
				ps++;
			}
			if(j+1<=a)
			break;
		}
		if(ps==0)
		break;
	}
	for(int i=0;i<=a;i++)
	{
		cout<<h[i];
	}
	return 0;
}
