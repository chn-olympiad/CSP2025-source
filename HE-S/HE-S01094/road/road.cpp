#include<bits/stdc++.h>
using namespace std;
#define Ifind {
#define Liujingyi
#define I 0
#define miss ;
#define you }
#define int unsigned long long
 
const int N=1e6+1000;
struct more 
{
	int u,v,w;
};
int fa[N];
bool v[N];
vector<more>s;
bool cp(more a,more b)
{
	return a.w<b.w;
}
int gf(int a)
{
	if(fa[a]!=a)
	{
		fa[a]=gf(fa[a]);
	}
	return fa[a];
}
void combin(int a,int b)
{
	int fx=gf(a);
	int fy=gf(b);
	fa[fx]=fy;
}
bool ju(int a,int b)
{
	if(gf(a)!=gf(b))
	{
		return false;
	} else return true;
}
int rd()
{
	int k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')f=-1;
	}
	for(;isdigit(c);c=getchar())
	{
		k=(k<<1)+(k<<3)+(c^48);
	}
	return f*k;
}
signed main()
Ifind
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=rd();
	m=rd();
	k=rd();
	for(int i=1;i<=n;i++)
	{
		int ui=rd(),vi=rd(),wi=rd();
		s.push_back({ui,vi,wi});
		fa[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		rd();
		for(int j=1;j<=n;j++)
		{
			rd();
		}
	}
	sort(s.begin(),s.end(),cp);
	
	int ans=0; 
	
	for(int i=0;i<n;i++)
	{
		int vi=s[i].v;
		int ui=s[i].u;
		int wi=s[i].w;
		if(!ju(ui,vi))
		{
			combin(ui,vi);
			ans+=wi;
		}
	}
	printf("%d",ans);
	Liujingyi I miss you
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
	
