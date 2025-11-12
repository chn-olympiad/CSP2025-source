#include <bits/stdc++.h>
using namespace std;
const int M=1000010;
struct E
{
	int x,y,z;
}a[M];
int m,q,lx;
string x;
int main()
{
	ifstream cin("replace.in");
	ofstream cout("replace.out");
	cin>>m>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		a[i].x=a[i].y=0;
		for(int j=0;j<x.length();j++)
		{
			if(x[i]=='b')continue;
			
			a[i].x++;
		}
		a[i].y=x.length()-1-a[i].x;
		cin>>x;
		for(int j=0;j<x.length();j++)
		{
			if(x[i]=='b')continue;
			
			a[i].z++;
		}
	}
	while(q--)
	{
		int a1=0,a2=0,ans=0;
		cin>>x;
		for(int j=0;j<x.length();j++)
		{
			
			if(x[j]=='b')continue;		
			a2++;	
		}
		lx=x.length();
		cin>>x;
		if(lx!=x.length())
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<x.length();j++)
		{
			
			if(x[j]=='b')continue;		
			a1++;	
		}
		for(int i=1;i<=m;i++)
		{
			if(a[i].x<=a2&&lx-a2-1>=a[i].y&&a1-a2 == a[i].z-a[i].x)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
