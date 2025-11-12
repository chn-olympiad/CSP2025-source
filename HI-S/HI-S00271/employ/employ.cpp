#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000];
string s;
int n=0,m=0;
int mm=0;
int man(int t,int x,int h,int nn)
{
	b[x]=1;
	if(a[x]>h)
	{
		if(s[t-1]=='1')
		{
			nn++;
		}
		else
		{
			h++;
		}
	}
	if(t==n)
	{
		if(nn>=m)
		{
			mm++;
			mm=mm%998244353;
			nn=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		if(i!=x&&b[i]!=1)
		{
			int t1=t+1;
			int x1=i;
			man(t1,i,h,nn);
		}
	}
	b[x]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		man(1,i,0,0);
	}
	cout<<mm<<endl;
	return 0;
}

