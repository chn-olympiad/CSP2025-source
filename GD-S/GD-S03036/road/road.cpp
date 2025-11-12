#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000010;
int n, m, k;
int p[N];
struct Road{
	int u, v, w;
}r[N], tmp[N];
struct Road2{
	int c;
	int a[N];
}v[15];
LL res;
bool cmp(Road a, Road b){
	return a.w < b.w;
}
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
LL work1(){
	int num = 0;
	LL res = 0;
	for(int i = 1;i <= n;i++) p[i] = i;
	sort(r + 1, r + m + 1, cmp);
	for(int i = 1;i <= m;i++){
		int a = find(r[i].u);
		int b = find(r[i].v);
		if(a == b) continue;
		p[a] = b;
		res += r[i].w;
		if(++num == n - 1) break;
	}
	return res;
}
void work2(){
	auto t1 = clock();
	int x = 1 << k;
	LL res = 1e18;
	for(int i = 1;i <= m;i++){
		tmp[i].u = r[i].u;
		tmp[i].v = r[i].v;
		tmp[i].w = r[i].w;
	}
	for(int i = 0;i < x;i++){
		int num = 0, sum = 0;
		for(int j = 0;j < k;j++){
			if((i >> j) & 1){
				num++;
				sum += v[j + 1].c;
				for(int k = 1;k <= n;k++){
					r[++m] = {n + num, k, v[j + 1].a[k]};
				}
			}
		}
		n += num;
		res = min(res, work1() + sum);
		if(clock() - t1 > 900){
			printf("%lld\n", res);
			return;
		}
		n -= num;
		m -= n * num;
		for(int j = 1;j <= m;j++){
			r[j].u = tmp[j].u;
			r[j].v = tmp[j].v;
			r[j].w = tmp[j].w;
		}
	}
	printf("%lld\n", res);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &r[i].u, &r[i].v, &r[i].w);
	}
	for(int i = 1;i <= k;i++){
		scanf("%d", &v[i].c);
		for(int j = 1;j <= n;j++){
			scanf("%d", &v[i].a[j]);
		}
	}
	if(!k) printf("%lld\n", work1());
	else work2();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
