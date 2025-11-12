#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#define int long long
#define N 10005
#define M 1000006
#define K 15
using namespace std;
#define isdigit(ch) ('0' <= ch && ch <= '9')
template<typename T>
void read(T&x) {
	x = 0;
	char ch = getchar();
	for (;!isdigit(ch);ch = getchar());
	for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48); 
}
int n,m,k,a[K][N],c[N],mn[N];
struct node{
	int u,v,w;
};
int fa[N],id[N];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	vector<node> ls;
	for (int i = 1;i <= m;i ++) {
		int u,v,w;
		read(u),read(v),read(w);
		ls.push_back({u,v,w});
	}
	for (int i = 1;i <= k;i ++) {
		read(c[i]);
		for (int j = 1;j <= n;j ++) read(a[i][j]);
	}
//	for (int i = 1;i <= n;i ++)
//		for (int j = i;j <= n;j ++)
//			for (int w = 1;w <= k;w ++)
//				ls.push_back({i,j,c[w] + a[w][i] + a[w][j]});
////	for (int w = 1;w <= k;w ++) {
////		int mnid = 1;
////		for (int i = 2;i <= n;i ++)
////			if (a[w][mnid] > a[w][i]) mnid = i;
////		for (int i = 1;i <= n;i ++)
////			if (i != mnid) ls.push_back({mnid,i,c[w] + a[w][mnid] + a[w][i]});
////	}
//	stable_sort(ls.begin(),ls.end(),[](node x,node y) {
//		return x.w < y.w;
//	});
//	int ans = 0;
//	for (int i = 1;i <= n;i ++) fa[i] = i;
//	for (auto i : ls) {
//		int x = find(i.u),y = find(i.v);
//		if (x != y) ans += i.w,fa[x] = fa[y];
//	}
//	cout << ans;
	//use boluo suanfa 
	int ltk = n;
	for (int i = 1;i <= n;i ++) fa[i] = i;
	int ans = 0;
	while(ltk != 1) {
//		set<int> st;
		for (int i = 1;i <= n;i ++) find(i);
		for (int i = 1;i <= n;i ++) mn[fa[i]] = 1e18,id[fa[i]] = 0;
//		st.insert(fa[i]);
		for (auto i : ls) {
			int x = find(i.u),y = find(i.v);
			if (x != y) {
				if (mn[x] > i.w) mn[x] = i.w,id[x] = y;
				if (mn[y] > i.w) mn[y] = i.w,id[y] = x;
			}
		}
		for (int w = 1;w <= k;w ++){
			int mn1 = 1e18,mn2 = 1e18,mnid1 = 0,mnid2 = 0;
			for (int i = 1;i <= n;i ++)
				if (mn1 > a[w][i]) mn1 = a[w][i],mnid1 = i;
			mnid1 = find(mnid1);
			for (int i = 1;i <= n;i ++)
				if (mn2 > a[w][i] && find(i) != mnid1) mn2 = a[w][i],mnid2 = i;
			mnid2 = find(mnid2);
			for (int i = 1;i <= n;i ++) {
				int x = find(i);
				if (x != mnid1) {
					if (mn[x] > c[w] + mn1 + a[w][i]) mn[x] = c[w] + mn1 + a[w][i],id[x] = mnid1;
				}
				else {
					if (mn[x] > c[w] + mn2 + a[w][i]) mn[x] = c[w] + mn2 + a[w][i],id[x] = mnid2;
				}
			}
		}
		for (int i = 1;i <= n;i ++) {
			int x = find(i),y = find(id[x]);
			if (x != y) {
				fa[x] = fa[y];
				ltk --;
				ans += mn[x];
			}
		}
//		cout << lxtk << '\n';
//		for (int i = 1;i <= n;i ++) cout << mn[i] << ' ';
//		cout << '\n';
	}
	printf("%lld\n",ans);
	return 0;
}
