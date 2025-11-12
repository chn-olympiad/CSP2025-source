#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const long long N=1e5+10;
//long long a[N][4];
struct node
{
	long long a,b,c;
}a[N];
struct snode
{
long long a,b,c,d,e;
const bool operator<(const snode rhs)const
{
if(this->a==rhs.a)
{
if(this->b==rhs.b)
{
if(this->c==rhs.c)
{
if(this->d==rhs.d)
{
return this->e<rhs.e;
}
return this->d<rhs.d;
}
return this->c<rhs.c;
}
return this->b<rhs.b;
}
return this->a<rhs.a;
}
};
set<snode> vis;
long long n;
long long ans;
void dfs(long long x,long long v,long long t1,long long t2,long long t3)
{
	snode temp;
	temp={x,v,t1,t2,t3};
	if(vis.count(temp))
	{
		return;
	}
	vis.insert(temp);
//	cout<<x<<' '<<v<<' '<<t1<<' '<<t2<<' '<<t3<<'\n';
	if(x==n+1)
	{
		ans=max(ans,v);
		return;
	}
	if(t1<n/2)
	{
		dfs(x+1,v+a[x].a,t1+1,t2,t3);
	}
	if(t2<n/2)
	{
		dfs(x+1,v+a[x].b,t1,t2+1,t3);
	}
	if(t3<n/2)
	{
		dfs(x+1,v+a[x].c,t1,t2,t3+1);
	}
}
bool cmp1(node x,node y)
{
	return x.a>y.a;
	
}
void treat()
{
	cin>>n;
	long long mx2=-1,mx3=-1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		mx2=max(mx2,a[i].b);
		mx3=max(mx3,a[i].c);
	}
	if(mx2==0&&mx3==0)
	{
		sort(a+1,a+n+1,cmp1);
		for(long long i=1;i<=n/2;i++)
		{
			ans+=a[i].a;
		}
		cout<<ans<<'\n';
		return;
	}
	if(n<=30)
	{
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		return;
	}
	
}
int main()
{
//	freopen("club.in","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;cin>>T;
	while(T--)
	{
		ans=0;
		vis.clear();
		treat();
	} 
	
	return 0;
}
