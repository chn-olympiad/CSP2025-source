#include<bits/stdc++.h>//luogu uid:956129
#define ll long long 
using namespace std;

namespace io
{
	inline int read(){int x=0,w=0;char c=0;while(!isdigit(c))w|=c=='-',c=getchar();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return w?-x:x;}
	template<typename T>void write(T x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10+'0');}
	template<typename T>void write_(T x){write(x),putchar(' ');}
	template<typename T>void writeln(T x){write(x),putchar('\n');}
}
using namespace io;

/*
注意:答案会爆掉longlong 

哈哈,读错题了,乡村不算城市啊,我还以为全是乡村呢，浪费了一小时的时间，失败了 

看看特殊性质：即：连接其中一个城市不需要花费
这不纯纯爽，直接捆绑在一起跑kruskal啊

然后来看全部的怎么做
那就是可以选择捆绑也可以选择不捆绑
这样，先捆上，然后再看用上没有，没用上就取消捆绑。
怎么捆呢，先和花费最小的捆在一起？
这样显然有问题啊，因为一但捆上就可能用上它了。
可以证明，被乡村所连接的两个连通块，一旦去掉这个乡村则一定不连通
但是是不是也不能不连接啊
这样，枚举每个乡村，对连通块进行优化。 

这道题是用来玩捆绑的吗（？ 
*/
const int N=1e4+10; 
int n,m,k,cnt,f[N],c[N][15];//a[i]表示第 i 个点的所连的边的边权和 
ll ans;
struct edge{int u,v,w;friend bool operator<(const edge&x,const edge&y){return x.w<y.w;}};
vector<edge> e;
unordered_map<int,int> mp[N],pre[N];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool judge(int x,int y){x=find(x),y=find(y);return x!=y;}
void uunion(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)f[x]=y;
}

void solve1()//16分 
{
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e)
	{
		if(judge(u,v)) uunion(u,v),ans+=w,cnt++;//kruskal跑答案
		if(cnt==n-1) break;
	}
	writeln(ans);
}

void solve2()//32分 
{
	//即：部分城市可以直接和乡村捆在一起玩。
	vector<int> v;
	for(int i=1;i<=k;i++)
	{
		v.clear();int pr=0;
		for(int j=1;j<=n;j++)
			if(c[j][i]==0) v.push_back(j);
		for(auto j:v)
		{
			if(!pr){pr=j;continue;}
			if(judge(pr,j)) uunion(pr,j),cnt++;
		}
		pr=find(pr);
		for(int j=1;j<=n;j++)
			if(c[j][i]!=0) e.push_back({pr,j,c[j][i]});
	}
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e)
	{
		if(judge(u,v)) uunion(u,v),ans+=w,cnt++;//kruskal跑答案
		if(cnt==n-1) break;
	}
	writeln(ans);
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	bool fl=0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		int x=0; 
		for(int j=0;j<=n;j++) c[j][i]=read(),x+=(c[j][i]==0);
		if(!(c[0][i]==0&&x>=2)) fl=1;
	}
//	if(k==0) solve1(),exit(0);
//	if(!fl) solve2(),exit(0);
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e)
		if(judge(u,v)) uunion(u,v),ans+=w,mp[u][v]=w,mp[v][u]=w;//kruskal跑答案
	for(int i=1;i<=k;i++)
	{
		int sum=c[0][i];
		//对于连通的怎么看最优答案：
		//断开重连更优就连
		//可是断开重连连的是两边的连通块，直接连两个点显然不行。
		// 
//		for(int j=1;j<=n;j++)
//			for(auto [to,w]:mp[j])
//				if(c[u][i]+c[to][i]<mp[u][to]) sum-=mp[u][to]-c[u][i]-c[to][i];
//		//接下来对于不连通的跑答案
//		e.clear();
//		for(int j=2;j<=n;j++) e.push_back(e[j])
	}
	return 0;
}
