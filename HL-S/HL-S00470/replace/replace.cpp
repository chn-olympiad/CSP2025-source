#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans=0;
bool f=0;
int maxa1,maxa2,maxa3;
int x1=0,x2=0,x3=0;
struct node
{
	int a1,a2,a3,maxn;
	bool pn=0;
}b[10001];
int x(int p)
{
	for(int j=0;j<n;j++)
	{
		if(b[j].maxn==b[j].a1)x1++;
		else if(b[j].maxn==b[j].a2)x2++;
		else x3++;
	}
	if (x1>p||x2>p||x3>p)
	{
		f=1;
	}
	x1=0,x2=0,x3=0;
}
bool cmp(int x,int y)
{
	return x>y;
}
int a1(int p)
{
	int a[100];
	int log=1;
	for(int j=0;j<n;j++)
	{
		if(b[j].pn==0)
		{
			a[log]=b[j].a1;
			log++;
		}
	}
	sort(a+1,a+log+1,cmp);
	//for(int i=1;i<=log;i++)
	//{
	//	cout<<a[i]<<" ";
	//}
	for(int i=1;i<=p;i++)
	{
		maxa1+=a[i];
	}
}
int a2(int p)
{
	int a[100];
	int log=1;
	for(int j=0;j<n;j++)
	{
		if(b[j].pn==0)
		{
			a[log]=b[j].a2;
			log++;
		}
	}
	sort(a+1,a+log+1,cmp);
	//for(int i=1;i<=log;i++)
	//{
	//	cout<<a[i]<<" ";
	//}
	for(int i=1;i<=p;i++)
	{
		maxa2+=a[i];
	}
}
int a3(int p)
{
	int a[100];
	int log=1;
	for(int j=0;j<n;j++)
	{
		if(b[j].pn==0)
		{
			a[log]=b[j].a3;
			log++;
		}
	}
	sort(a+1,a+log+1,cmp);
	//for(int i=1;i<=log;i++)
	//{
	//	cout<<a[i]<<" ";
	//}
	for(int i=1;i<=p;i++)
	{
		maxa3+=a[i];
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int p=n/2;
		for(int i=0;i<n;i++)
		{
			cin>>b[i].a1>>b[i].a2>>b[i].a3;
			b[i].maxn=max(b[i].a1,max(b[i].a2,b[i].a3));
		}
		x(p);
		if(f==0)
		{
			for(int i=0;i<n;i++)
			{
				ans+=b[i].maxn;	
			}
			f=0;
			cout<<ans<<endl;
		}
		else
		{
			a1(p);
			a2(p);
			a3(p);
			ans=maxa1+maxa2+maxa3;
			cout<<ans<<endl;
		}
	}
	return 0;
}

