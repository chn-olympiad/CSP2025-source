#include <bits/stdc++.h>

using namespace std;

int n, k, a[500010], c[500010];
struct Node{
	int l, v;
} f[500010];
vector<int> p[2000010];

int calc(int x){
	int y = k ^ c[x];
	if (p[y].empty())
		return 0;
	else{
		int L = -1, R = p[y].size();
		while (L + 1 < R){
			int M = (L + R) / 2;
			if (p[y][M] >= f[x - 1].l)
				R = M;
			else
				L = M;
		}
		if (p[y][L + 1] < x && p[y][L + 1] >= f[x - 1].l)
			return 1;
		else
			return 0;
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= 500005; i++)
		f[i].v = -1;
	c[0] = 0;
	p[0].push_back(0);
	for (int i = 1; i <= n; i++){
		c[i] = c[i - 1] ^ a[i];
		p[c[i]].push_back(i);
	}
	f[0].v = 0, f[0].l = 0;
	for (int i = 1; i <= n; i++){
		int tmp = calc(i);
		f[i].v = f[i - 1].v + tmp;
		if (!tmp)
			f[i].l = f[i - 1].l;
		else
			f[i].l = i;
	}
	printf("%d", f[n].v);
	return 0;
}
