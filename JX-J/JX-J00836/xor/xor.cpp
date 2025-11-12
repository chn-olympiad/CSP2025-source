//A, B xing zhi = zhi jie shu chu "0" ?
//zhong si ling yao chong chu jiang hu le ma?

//wo de bu fen fen jie fa hao xie men, gan jue cha chong lv < 1%

//10:13 ben ying gai TLE de da yang li gua le, hen huang(li lun shang wo de tan xin bu ying gai chu xian chu le chao shi yi wai de ren he wen ti)

//10:43 gai bu chu lai, diu le
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
struct node {
	int l, r;
}id[N];
int n, a[N], cnt = 0;
long long k, ans = 1;

bool cmp(node i, node j) {
	if (i.r == j.r) {
		return i.l < j.l;
	}
	return i.r < j.r;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		long long tmp = 0;
		for (int j = i; j <= n; j++) {
			tmp ^= a[j];
//			cout << tmp << " ";
			if (tmp == k) {
				cnt++;
				id[cnt] = (node){i, j};
			}
		}
//		cout << '\n';
	}
	
	sort(id + 1, id + cnt + 1, cmp);
	
	node last = id[1];
//	cout << cnt << '\n';
	for (int i = 2; i <= cnt; i++) {
		if (id[i].l > last.r) {
			ans++;
			last = id[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
