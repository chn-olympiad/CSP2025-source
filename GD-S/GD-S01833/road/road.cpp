#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
char *p1,*p2,buf[100000];
#define nc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++
int read()
{
	int x=0;
	char ch=nc();
	for(;ch<48||ch>57;ch=nc());
	for(;ch>47&&ch<58;ch=nc()) x=(x<<3)+(x<<1)+ch-48;
	return x;
}
void write(long long x)
{
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}
int n,m,k;
struct edge{
	int u,v;
	long long w;
	bool operator < (const edge&x){
		return w<x.w;
	}
};
constexpr long long INF=1ll<<60;
vector<edge> d,t,td;
long long aij[15][10010],cj[15];
int f[10010];
long long cost,mi=INF;
int fa(int x)
{
	if(f[x]!=x) f[x]=fa(f[x]);
	return f[x];
}
void mit()
{
	for(int i=n;i;--i) f[i]=i;
	for(int i=0;i<td.size();++i)
	{
		int fu=fa(td[i].u),fv=fa(td[i].v);
		if(fu==fv) continue;
		f[fu]=fv;
		cost+=td[i].w;
		if(cost>mi) return;
	}
	return;
}
void cl()
{
	int wi=0,wj=0;
	sort(t.begin(),t.end());
	td.clear();
	for(;wi<d.size()&&wj<t.size();)
	{
		if(d[wi]<t[wj])
		{
			td.push_back(d[wi]);
			++wi;
		}
		else
		{
			td.push_back(t[wj]);
			++wj;
		}
	}
	for(;wi<d.size();++wi) td.push_back(d[wi]);
	for(;wj<t.size();++wj) td.push_back(d[wj]);
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=m;i;--i)
	{
		int u=read(),v=read();
		long long w=read();
		d.push_back({u,v,w});
	}
	for(int i=0;i<k;++i)
	{
		cj[i]=read();
		if(!cj[i])
		{
			++n;
			for(int j=1;j<=n;++j)
			{
				long long w=read();
				d.push_back({n,j,w});
			}
			--i;
			--k;
			continue;
		}
		for(int j=1;j<=n;++j)
		{
			aij[i][j]=read();
		}
	}
	sort(d.begin(),d.end());
	for(int sol=(1ll<<k)-1;sol>=0;--sol)
	{
		cost=0;
		bool flag=1;
		int cnt=0;
		t.clear();
		for(int i=0;i<k;++i)
		{
			if((sol>>i)&1)
			{
				cost+=cj[i];
				++cnt;
				if(cost>mi)
				{
					flag=0;
					break;
				}
				for(int j=1;j<=n;++j)
				{
					t.push_back({n+cnt,j,aij[i][j]});
				}
			}
		}
		if(flag)
		{
			cl();
			n+=cnt;
			mit();
			n-=cnt;
			mi=min(mi,cost);
		}
	}
	write(mi);
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
