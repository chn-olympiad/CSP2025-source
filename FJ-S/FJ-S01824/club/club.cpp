#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int la=0,lb=0,a[N],ja=0;//a[]记录被m 拿走的是第几个 
struct no
{
	int a,b,c;
}m[N];
int am(no aa,no bb)
{
	return aa.a>bb.a;
}
int aam(no aa,no bb)
{
	return aa.b>bb.b;
}
int aaam(no aa,no bb)
{
	return aa.c>bb.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		ja=0;
		for(int i = 0 ; i < N ;i++)a[i]=0;
		int ret=0,bo=0,b=0;
		int n;
		cin >>n;
		for(int i = 0 ; i <  n ; i++)
		{
			cin >>m[i].a>>m[i].b>>m[i].c;
			if(m[i].b!=0||m[i].c!=0)
			{
				bo=1;
			}
			if(m[i].c!=0)
			{
				b=1;
			}
		}
		if(bo==0)
		{
			sort(m,m+n,am);
			for(int i = 0 ; i < n/2 ; i++)
			{
				ret+=m[i].a;
			}
			cout << ret<<endl;
		}
		else if(n==2)
		{
			sort(m,m+n,am);
			ret=max(m[0].a+max(m[1].b,m[1].c),ret);
			sort(m,m+n,aam);
			ret=max(m[0].b+max(m[1].a,m[1].c),ret);
			sort(m,m+n,aaam);
			ret=max(m[0].c+max(m[1].a,m[1].b),ret);
			cout <<ret<<endl;
		}
		else if(b==0)
		{
			for(int i = 0 ; i < n ; i++)
			{
				
				{
					for(int j = 0 ; j < ja ; j++)
					{
						if(m[i].a+m[a[j]].b>m[i].b+m[a[j]].a)
						{
							ret+=-m[a[j]].a+m[i].a+m[a[j]].b;
							a[ja]=i;
							ja++;
						}
					}
				}
				
				{
					for(int j = 0 ; j < ja ; j++)
					{
						if( m[i].b+m[a[j]].a>m[i].a+m[a[j]].b)
						{
							ret+=-m[a[j]].b+m[i].b+m[a[j]].a;
							a[ja]=i;
							ja++;
						}
					}
				}
				if(la>n/2&&lb>n/2
				)
				{
					if(m[i].a>m[i].b)
					{
						a[ja]=i;
						ja++;
						ret+=m[i].a;
					}
					else
					{
						a[ja]=i;
						ja++;
						ret+=m[i].b;
					}
				}
			}
			cout <<ret<<endl;
		}
	}
	return 0;
}
