#include<bits/stdc++.h>
#define ll long long
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
inline int read(){int x=0;bool b=0;signed c=getchar();while(c<48||c>57)b=c==45,c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return b?-x:x;}
inline void write(ll x,signed c){if(!x){putchar(48),putchar(c);return;}if(x<0)x=-x,putchar(45);signed i=0,a[32];while(x)a[++i]=x%10^48,x/=10;while(i)putchar(a[i--]);putchar(c);}
struct st
{
	int a,jl;
};
bool operator<(st a,st b)
{
	return a.jl>b.jl;
}
int n,m,k,x,y,z,mx,a[20],mn[10100];
ll ans=1e18;
bitset<10100>b;
vector<st>v[10100];
priority_queue<st>q;
ll prim(int &s)
{
	ll sum=0;
	b=0,q.push({1,0}),memset(mn,0x7f,sizeof(mn));
	for(int i=1;i<=k;i++)
		b[i+n]=s&(1<<i-1),sum+=(!b[i+n])*a[i];
	while(q.size())
	{
		st u=q.top();
		q.pop();
		if(b[u.a])
			continue;
		b[u.a]=1,sum+=u.jl;
		for(st i:v[u.a])
			if(!b[i.a]&&i.jl<mn[i.a])
				q.push({i.a,i.jl}),mn[i.a]=i.jl;
	}
	return sum;
}
signed main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		x=read(),y=read(),z=read(),v[x].push_back({y,z}),v[y].push_back({x,z});
	for(int i=1;i<=k;i++)
	{
		a[i]=read(),mx=max(mx,a[i]);
		for(int j=1;j<=n;j++)
			x=read(),mx=max(mx,x),v[i+n].push_back({j,x}),v[j].push_back({i+n,x});
	}
	if(!mx)
	{
		write(0,10);
		return 0;
	}
	for(int i=0;i<(1<<k);i++)
		ans=min(ans,prim(i));
	write(ans,10);
	return 0;
}
/*
夏夜空 出现在遥远的记忆 
绽放的 璀璨花火拥着繁星 
消失前 做出最温柔的给予 
一如那些模糊身影的别离 

石墨保佑我不挂分 
说好的给一个虚拟机呢？ 
旁边的6：00还在调T1 
他好像调完了 
luogu uid:984809
*/
