#include<bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int a,b,c,op,now;
}x[100010];
int a,b,c;
bool cmp1(node a,node b)
{
	return abs(a.a-a.b)<abs(b.a-b.b);
}
bool cmp2(node a,node b)
{
	return a.c-a.now>b.c-b.now;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
		cin>>n;
		a=b=c=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b) x[i].op=1,x[i].now=x[i].a,a++;
			else x[i].op=2,x[i].now=x[i].b,b++;
		}
		sort(x+1,x+n+1,cmp1);
		while(a<n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(x[i].op==2)
				{
					x[i].op=1,x[i].now=x[i].a;
					a++;
				}
				if(a==n/2) break;
			}
		}
		while(a>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(x[i].op==1)
				{
					x[i].op=2,x[i].now=x[i].b;
					a--;
				}
				if(a==n/2) break;
			}
		}	
		sort(x+1,x+n+1,cmp2);
	    for(int i=1;i<=n&&c<n/2;i++)
	    {
			if(x[i].c-x[i].now>0)
			{
				if(x[i].op==1) a--;
				else b--;
				c++,x[i].op=3,x[i].now=x[i].c;
			}
			else break;
	    }
	    sort(x+1,x+n+1,cmp1);
	    for(int i=n;i>=1;i--)
	    {
			if(b<n/2&&x[i].op==1&&x[i].a<x[i].b)
			{
				a--,b++;
				x[i].op=2,x[i].now=x[i].b;
		    }
		    if(a<n/2&&x[i].op==2&&x[i].b<x[i].a)
		    {
				a++,b--;
				x[i].op=1,x[i].now=x[i].a;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=x[i].now;
		}
		cout<<ans<<'\n';
	}
    return 0;
}
