#include<bits/stdc++.h>
using namespace std;
int t,n,e,f,flag;
int b,c,d;
long long sum;
int aaa,bbb,ccc,ddd,eee,fff;
int g[1000000],h[1000000],k[1000000],x,y;
struct node
{
	int a1,a2,a3,flag=0;
}a[1000000];
bool cmp1(int a,int b)
{
	return a>b;
}
bool cmp2(int a,int b)
{
	return a>b;
}
bool cmp3(int a,int b)
{
	return a>b;
}
bool cmp4(node c,node d)
{
	return c.a1>d.a1;
}
bool cmp5(node c,node d)
{
	return c.a2>d.a2;
}
bool cmp6(node c,node d)
{
	return c.a3>d.a3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		
		if(n==2)
		{
			for(int i=1;i<=n;i++)
			{
				int aa=a[i].a1+a[i+1].a2;
				int bb=a[i].a1+a[i+1].a3;
				int cc=a[i].a2+a[i+1].a1;
				int dd=a[i].a2+a[i+1].a3;
				int ee=a[i].a3+a[i+1].a1;
				int ff=a[i].a3+a[i+1].a2;
				int gg=max(aa,bb);
				int hh=max(cc,dd);
				int ii=max(ee,ff);
				cout<<max(max(gg,hh),ii)<<endl;
				break;
			}
		}
		else
		{
			sort(a+1,a+n+1,cmp4);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i].a1;
			}
			
		    cout<<sum<<endl;
		    break;
		}
	}
	return 0;
}
