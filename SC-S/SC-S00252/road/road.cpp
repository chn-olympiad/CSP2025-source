#include<bits/stdc++.h>
#define ll long long
#define PR pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 1e4+50, MAXM = 1e6+5, MAXK = 15;
int n, m, k, e0, e, a[MAXK][MAXN], fa[MAXN];

inline int Read(){
	int x = 0;
	char c = getchar();
	while(!isdigit(c))	c = getchar();
	while(isdigit(c))	x = x*10+c-'0', c = getchar();
	return x;
}

inline void Write(int x){
	if(x/10)	Write(x/10);
	putchar(x%10+'0');
	return;
}

inline int Find(int x){//maybe add size later.
	if(fa[x] != x)	fa[x] = Find(fa[x]);
	return fa[x];
}

struct Node{
	int u, v, w;
	bool operator < (const Node &tmp)const{
		return w < tmp.w;
	}
} edge1[MAXM], edge2[MAXN*MAXK+MAXM];

inline void Kruskal(){
	for(int i = 1; i <= n; i++)	fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u = Find(edge1[i].u), v = Find(edge1[i].v);
		if(u == v)	continue;
		fa[u] = v;
		edge2[++e0] = edge1[i];
	}
	return;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = Read(), m = Read(), k = Read();
	for(int i = 1; i <= m; i++){
		int u = Read(), v = Read(), w = Read();
		edge1[i] = {u, v, w};
	}
	sort(edge1+1, edge1+1+m);
	Kruskal();
	for(int i = 0; i < k; i++)
		for(int j = 0; j <= n; j++)	scanf("%d", &a[i][j]);
//	for(int i = 1; i <= m; i++)	edge2[i] = edge1[i];
//	e0 = m;
	ll ans = 1e18;
	for(int i = 0; i < 1<<k; i++){
		e = e0;
		ll sum = 0;
		for(int j = 0; j < k; j++){
			if(!(i&(1<<j)))	continue;
			sum += a[j][0];
			for(int x = 1; x <= n; x++)	edge2[++e] = {j+1+n, x, a[j][x]};
		}
		sort(edge2+1, edge2+1+e);
		for(int j = 1; j <= n+k; j++)	fa[j] = j;
		for(int j = 1; j <= e; j++){
			int u = Find(edge2[j].u), v = Find(edge2[j].v);
			if(u == v)	continue;
			fa[u] = v;
			sum += edge2[j].w;
		}
		ans = min(ans, sum);
	}
	cout<<ans;
	
	return 0;
}
/*
最小生成树，但是。。。

一个很暴力的想法是直接 2^k 枚举新增哪些点。但我感觉这应该不行。

我草，我想到那天做的那道学校模拟赛。
这里可以用 edited Prim？
我草，我草，我草，给做到类似题了
再也不诋毁 tfqz 模拟赛了
我爱你 

有点忘了 prim 怎么写的。

好像和模拟赛那道题也不太一样。想清楚细节。
这个算法我个人感觉还是比较对的。
主要的问题在有贡献可能被多算。
比如，这个乡镇，它被建出来是没有意义的，但是它的贡献还是会被算到总和里面去。
那么，我们是否可以判断：如果它没有起到任何更新作用，那么我们就不累加其贡献？？？
非也。这样是有问题的。

考虑这个新增节点实际上在解决什么问题。
如果对于一棵子树，使用新增节点的代价 < 使用 kruskal 连通它们的代价，那就可以考虑。

有一点猜想。
先在原图上跑出最小生成树。特别是处理出 prim 的 dis 数组。 
注意到我们只是没有办法支持 O(m2^k) 复杂度，但是可以做 O(n2^k)。
或许这样就可以了。

还是不对。。。伪掉了。
问题在可能连出环。
 
我们还是回到 kruskal。
先建出来最小生成树，然后枚举必选哪些乡镇。
然后呢？
假如我们得到当前这个点应该连哪些点，我们都不见得能调整出答案。

我可能脑残了。
我们想将最小生成树跑出来，然后再在剩下的子图上面跑一遍，这样不就行了吗？？？
当然，这样的复杂度是 O(2^kn log n)。我不知道还能不能做到更好。
可以把有用的边全部拎出来，做归并排序。
可能常数会小一些。
感觉能过，直接写吧。

再仔细斟酌一下那个结论。是否一定只保留最小生成树中的边？
我觉得没毛病。
伪了啊。。。 
*/