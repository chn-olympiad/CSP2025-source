#include<bits/stdc++.h>
using namespace std;

struct line{
	long long a, b, c;
}l[2000005];

struct dd{
	long long se = 0;
	long long bi[10005];
}d[15];
long long n, m, co, x, y, z, ans = -1, tot, nt, ll, f[15], fa[10025];

bool cmp(line p,line q){
	return p.c < q.c;
}

long long find(long long k){
	if(fa[k] == k)
		return k;
	return fa[k] = find(fa[k]);
}

void prim(long long k){
	tot = nt;
	for(int i = 1; i <= n + co; i++)
		fa[i]=i;
	if(k){
		for(int i = 1; i <= n; i++){
			l[++ll] = (line) {n+k, i, d[k].bi[i]};
		}
	}
	sort(l + 1, l + ll + 1, cmp);
	for(int i = 1; i <= ll; i++){
		int x = find(l[i].a), y = find(l[i].b);
		if(x != y){
			tot += l[i].c;
			fa[x] = y;
		}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &co);
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &l[i].a, &l[i].b, &l[i].c);
	}
	ll = m;
	for(int i = 1; i <= co; i++)
	{
		cin >> d[i].se;
		for(int j = 1; j <= n; j++)
			cin >> d[i].bi[j];
	}
	prim(0);
	ans = tot;
	for(int i = 1; i <= co; i++){
		nt+=d[i].se;
		prim(i);
		if(tot <= ans)
			ans = tot;
		else{
				ll-=n;
				nt-=d[i].se;
		}
	}
	cout << ans;
	return 0;
}
