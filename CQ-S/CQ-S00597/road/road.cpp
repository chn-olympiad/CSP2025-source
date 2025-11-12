#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10,M = 1e4+10,O = 13;
inline void read(int &x)
{
	x = 0; int f = 1; char c = getchar();
	while(c != '-' && (c < '0' || '9' < c)) c = getchar();
	if(c == '-') c = getchar(),f = -1;
	while('0' <= c && c <= '9') x = x*10+c-'0',c = getchar();
	x *= f;
}
int n,m,k,f[N],v[O],c[O],fx,fy,x,y,z,ans,sum,cnt,cnt1,cnt3,dw,L[O],bj[O],cnt2,o,ly,id;
struct w
{
	int x,y,z;
}a[N],b[O][M],T[M];
inline bool cmp(w x,w y){ return x.z < y.z; }
int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
void dfs(int x,int y)
{
	if(x > k)
	{
		for(int i = 1;i <= n+k;i++) f[i] = i; cnt2 = o = ly = 0; ly = n-1;
		for(int i = 1;i <= k;i++) if(v[i]) bj[++cnt2] = i,L[cnt2] = 1,ly += n;//ly为边数 
		dw = 1; sum = y; cnt3 = 0;
		while(1)//保证联通能结束 
		{
			id = 0;
			if(dw <= cnt) z = T[dw].z;
			else z = 1e18;
			for(int i = 1;i <= cnt2;i++)
				if(L[i] <= n && b[bj[i]][L[i]].z < z) z = b[bj[i]][L[i]].z,id = i;
			if(id == 0) x = T[dw].x,y = T[dw].y,dw++;
			else x = b[bj[id]][L[id]].x,y = b[bj[id]][L[id]].y,L[id]++;
			fx = find(x),fy = find(y);
			if(fx != fy)
			{
				f[fx] = fy,sum += z,o++;
				if(o == n+cnt2-1 || sum >= ans) break;//连通了或者一定不优了 
			}
		}//并在一起跑，随机情况下会跑的更快 
		ans = min(ans,sum);//取最小值 
		return;
	}
	v[x] = 1,dfs(x+1,y+c[x]);
	v[x] = 0,dfs(x+1,y);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	read(n),read(m),read(k);
	for(int i = 1;i <= m;i++) read(a[i].x),read(a[i].y),read(a[i].z);
	sort(a+1,a+1+m,cmp);
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= m;i++)
	{
		x = find(a[i].x),y = find(a[i].y);
		if(x != y)
		{
			f[x] = y,T[++cnt] = a[i],ans += a[i].z;
			if(cnt == n-1) break;
		}
	}
	for(int i = 1;i <= k;i++)
	{
		read(c[i]);
		for(int j = 1;j <= n;j++)
			read(b[i][j].z),b[i][j].x = i+n,b[i][j].y = j;
		sort(b[i]+1,b[i]+1+n,cmp);
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
/*
先跑出初始的最小生成树
然后其他边一定是没用的
然后2^k选点然后在跑
本来都是有序的，可以直接类归并的方式合并
复杂度大致是2^k*n*并查集复杂度，有一些冗余感觉没啥大问题 
*/
