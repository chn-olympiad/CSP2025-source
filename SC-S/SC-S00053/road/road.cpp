#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,x,ans,minn=10000000000001,f[10001],z[10001];
bool ts=true;

struct line
{
	int start;
	int to;
	int value;
	int used; 
}a[1000001];

bool cmp(line q,line p)
{
	return q.value<p.value;
}

int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void kruskal()
{
	for(int i=1;i<=m;++i)
	{
		int q=find(a[i].start),p=find(a[i].to);
		if(q==p) continue;
		f[q]=p;
		ans+=a[i].value;
		a[i].used=1;
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i) cin>>a[i].start>>a[i].to>>a[i].value;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n+1;++j)
		{
			cin>>x;
			z[i]+=x;
			if(x!=0) ts=false;
		}
		cout<<z[i]<<endl;
		minn=min(minn,z[i]);
	}
	if(ts)
	{
		cout<<0;
		return 0;
	}
	kruskal();
	cout<<min(minn,ans);
	return 0;
}

/*
T2又是啥阴？一眼望去kruskal，结果还有什么中转站？艹
但是kruskal似乎可以骗到分？ 

《安魂谣》 
我看见天空在哭泣
我听闻有你的声音 
我嗅到思念在荆棘中盛开 
我从日落的方向走来
大地和玫红是你的温床
xx和xx是你的浓妆
我会将希望编织成飞舞的木棉花 
直到岩石铭记花香 
哭泣的人儿啊
请你轻轻闭上双眼
待到黄昏落幕在至暗的时代 
我将应许你朝霞与蓝天 
（有点忘词，问题不大） 
*/


