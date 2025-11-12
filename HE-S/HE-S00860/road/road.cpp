#include<bits/stdc++.h>
#define ll long long
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x*10+c-'0'),c=getchar();
	return x*f;
}
//记得改成 ll long long，注意快读和输出也要 long long 类型 
using namespace std;
const int QAQ=1e6+19,ovo=11000;
const int inf=2e9;
const ll chaoji=1e18;
int n,m,k,cnt;
struct llll {int v,w;} a[11][ovo];
bool pai2(llll x,llll y)
{
	if(x.w==y.w) return x.v<y.v;
	return x.w<y.w;
}
struct xxx {int u,v,w;} d[QAQ],zhen[QAQ],cun[QAQ];
bool pai1(xxx a,xxx b)
{
	if(a.w==b.w)
	{
		if(a.u==b.u) return a.v<b.v;
		return a.u<b.u;
	}
	return a.w<b.w;
}
int f[QAQ],c[QAQ],kai[11],shi[11];
int find(int x) {return (x==f[x])?x:(f[x]=find(f[x]));}
ll ans;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=chaoji;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		d[i].u=read();
		d[i].v=read();
		d[i].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j].w=read(),a[i][j].v=j;
		sort(a[i]+1,a[i]+n+1,pai2);
	}
	sort(d+1,d+m+1,pai1);
	for(int i=1;i<=n;i++) f[i]=i;
	int ok=0;
	for(int i=1;i<=m;i++)
	{
		int x=d[i].u,y=d[i].v,z=d[i].w;
		int o1=find(x),o2=find(y);
		if(o1==o2) continue;
		f[o1]=o2;
		zhen[++cnt]=d[i];
		ok++;
		if(ok==n-1) break;
	}
	for(int s=0;s<(1<<k);s++)
	{
		int mudi=n;// 目的  
		for(int i=1;i<=n+k;i++) f[i]=i;
		int hao=0;
		ll da=0;
		
		int zz=0,top=0;
		
		for(int i=1;i<=k;i++)
		{
			if((s>>(i-1))&1)
			{
				kai[i]=1;
				mudi++;
				da+=c[i];
				shi[++top]=i;
				if(da>=ans)
				{
					zz=1;
					break;
				}
			}
		}
		if(zz) continue;
		
//		cout<<"!!!!!!!!!   "<<s<<'\n';
		
		kai[0]=1;
		while(hao<mudi-1)
		{
			int mi=inf,wei=0;
			if(kai[0]<=cnt)
			{
				mi=zhen[kai[0]].w,wei=0;
			}
			for(int i=1;i<=top;i++)
			{
				int nw=shi[i];
				if(kai[nw]>n) continue;
				int z=a[nw][kai[nw]].w;
				if(z<mi)
				{
					mi=z;
					wei=nw;
				}
			}
			int x,y,z;
			if(wei==0)
			{
				x=zhen[kai[0]].u,y=zhen[kai[0]].v,z=zhen[kai[0]].w;
			}
			else
			{
				x=wei+n,y=a[wei][kai[wei]].v,z=a[wei][kai[wei]].w;
			}
			kai[wei]++;
			int o1=find(x),o2=find(y);
			if(o1==o2) continue;
			f[o1]=o2;
			da+=z;
			hao++;
			
			
//			cout<<"!!!   "<<x<<" "<<y<<" "<<z<<'\n';
			
			if(da>=ans) break;
			if(hao==mudi-1) break;
		}
		if(hao==mudi-1&&da<ans) ans=da;
	}
	cout<<ans;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



k<=10 状压
n<=10000


DP 很可做 

枚举城市化的乡镇
等待思考：终态乡镇连通，故一个城市连通费用为 min 相连的乡镇 

等待思考：若无这 k 个东西则为若干连通块相连问题，总共 kn 条边。

等待思考：思考一下任意城市原本就可以连通。

我是不是可以在原图跑一个最小生成树，枚举乡镇做最小生成树？
好像可以。但是只能跑 2^k*m log (m+nk) 有点炸卡卡常数 64pts 

思考一下 A 性质：
这时我们贪心全选可以做到 m log m ？不对我们显然一些点可以不连通。
A 性质就是说所有乡镇都免费使用，且有一条免费边。
那我直接把这个乡镇合并到他免费的那个城市跑最小生成树就可以了。72pts


最小生成树应该是没跑了？
A 性质是否启发我们思考合并？
我如果在原图跑一个最小生成树，然后考虑加入乡镇呢？这个好像不太好考虑。

大胆猜：我是不是把每个乡镇合并到他相邻花费最小的那个节点就可以了？ 

性质：发现乡镇之间无连边。
	那么图应该示意为以若干乡镇为根的树，然后再把这些树最小代价地连起来。
	我们枚举点和他选择的乡镇，不对。
	
	这个性质启发是说乡镇 



等待思考：这不会是树形 DP 把？
思考从 1 开始跑
f[i][S]：[1,i] 的节点已经占了 S 里的乡镇的最小费用。

转移时，我们 i+1 可以选择新开一个乡镇或者选择 S 里面的乡镇或 [1,i] 的边连。

这时候我们会发现最后 f[n][s] 实际上可能不连通。
如果我们钦定 f[i][s] 表示 [1,i] 节点都连通且开了 s 的最小费用呢？
i+1 可以从 [1,i] 里随便连一个。
但是显然有一个问题就是，我们合法情况可能是 i+1 向后面连边然后后面再往前连回来的情况。


诶，我发现原图最小生成树的边才有可能加入新的最小生成树，也就是把那些边拿下来跑就可以了？
2^k*(n+kn) log (n+kn)？？？

我好傻。卡卡常数应该能过。 

诶我好像可以省去快排。 


*/
