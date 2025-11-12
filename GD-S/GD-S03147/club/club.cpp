#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5+10;
int t, n, cnt[10];

struct pzh{
	int a, b, c, maxv;
}a[N];

bool cmp(pzh x, pzh y){
	return x.maxv > y.maxv;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; j++){
			cin >> a[j].a >> a[j].b >> a[j].c;
			a[j].maxv = max(max(a[j].a, a[j].b),a[j].c);
		}
		sort(a+1, a+n+1, cmp);
		long long ans = 0;
		for (int j = 1; j <= n; j++){
			int m = -1e9, id = 0;
			if (cnt[1] < n / 2){
				if (a[j].a == m){
					if(cnt[id] > cnt[1]){
						id = 1;
					}
				}
				if (a[j].a > m){
					m = a[j].a;
					id = 1;
				}
			}
			if (cnt[2] < n / 2){
				if (a[j].b == m){
					if(cnt[id] > cnt[2]){
						id = 2;
					}
				}
				if (a[j].b > m){
					m = a[j].b;
					id = 2;
				}
			}
			if (cnt[3] < n / 2){
				if (a[j].c == m){
					if(cnt[id] > cnt[3]){
						id = 3;
					}
				}
				if (a[j].c > m){
					m = a[j].c;
					id = 3;
				}
			}
			ans += m;
			cnt[id]++;
		}
		cout << ans << endl;
	}
	return 0;
}
