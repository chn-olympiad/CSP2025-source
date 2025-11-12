#include <bits/stdc++.h>
using namespace std;
int n,m,k,scnt=0;
struct side
{
	int u,v,w;
	bool operator < (const side&a) const
	{
		return w < a.w;
	}
} edge[5100001];
int c[11021],a[20][10021],father[11021];
void init(int n)
{
	for(int i=1;i<=n;i++) father[i]=i;
}
int find(int x)
{
	if(father[x] == x) return x;
	else
	{
		father[x]=find(father[x]);
		return father[x];
	}
}
void merge(int x,int y)
{
	father[find(x)]=father[find(y)];
}
long long ans=0,cnt=0;
long long Kruscal()
{
	init(n+k);
	for(int i=1;i<=scnt;i++)
	{
		if(find(edge[i].u) == find(edge[i].v)) continue;
		else
		{
			cnt++;ans+=edge[i].w;
			merge(edge[i].u,edge[i].v);
		}
		if(cnt == n+k-1) break;
	}
	return ans;
}
int read()
{
	int base=1,res=0;
	char ch=getchar();
	while(!(ch == '-'||'0' <= ch&&ch <= '9')) ch=getchar();
	if(ch == '-') 
	{
		base=-1;
		ch=getchar();
	}
	while('0' <= ch&&ch <= '9')
	{
		res *= 10;
		res += ch-'0';
		ch=getchar();
	}
	return res*base;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) edge[i].u=read(),edge[i].v=read(),edge[i].w=read();
	scnt=m;
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		ans += c[i];
		for(int j=1;j<=n;j++) 
		{
			a[i][j]=read();
			++scnt;
			edge[scnt].u = n+i,edge[scnt].v = j,edge[scnt].w = a[i][j];
		}
	}
	sort(edge+1,edge+1+scnt);
	cout << Kruscal();
	return 0;
}