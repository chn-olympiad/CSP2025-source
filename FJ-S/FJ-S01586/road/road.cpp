#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int head[100050],c[15];
int find(int x) {
	return head[x] == x?x:head[x] = find(head[x]);
}
struct node{
	int x,y,w;
	friend bool operator <(node a,node b) {
		return a.w < b.w;
	}
}ed[2000005];
int cnt = 0;
int ans = 0;
//k = 0 or A
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
void k_0() {
	sort(ed + 1,ed + cnt + 1);
	int en = 0;
	for(int i = 1;i <= cnt;i++) {
		int p = find(ed[i].x),q = find(ed[i].y);
		if(p != q) {
			head[q] = p;
			en++;
			ans += ed[i].w;
		}
		if(en == n + k - 1) break;
	}
	printf("%lld\n",ans);
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i = 1;i <= n + k + 1;i++) head[i] = i;
	for(int i = 1;i <= m;i++) {
		cnt++;
		scanf("%lld %lld %lld",&ed[cnt].x,&ed[cnt].y,&ed[cnt].w);
		//printf("%lld\n",cnt);
	}
	int sum = 0;
	for(int i = 1;i <= k;i++) {
		scanf("%lld",&c[i]),sum += c[i];
		for(int j = 1;j <= n;j++) {
			ed[++cnt].x = n + i;
			ed[cnt].y = j;
			scanf("%lld",&ed[cnt].w);
		}
	}
	if(k == 0 or sum == 0) {
		k_0();
		return 0;
	}
	return 0;
}

