#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int t , n , a , b , c;
int ans;
int index[N];
struct subject{
	int l , inl;
	int m , inm;
	int s , ins;
};
subject club[N];
bool cmp(subject a , subject b) {
	return a.l > b.l;
}

int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%lld" , &t);
	while(t--) {
		scanf("%lld" , &n);
		for(int i = 1 ; i <= n ; i++) {
			scanf("%lld%lld%lld" , &a , &b , &c);
			index[a] = 1 ; index[b] = 2 ; index[c] = 3;
			int maxn = max(a , max(b , c)) , minn = min(a , min(b , c));
			int midn = a + b + c - maxn - minn;
			club[i].l = maxn ; club[i].inl = index[maxn];
			club[i].m = midn ; club[i].inm = index[midn];
			club[i].s = minn ; club[i].ins = index[minn];
		}
		
		int sum[5] = {0};
		for(int i = 1 ; i <= n ; i++) {
			sum[club[i].inl]++;
		}
		
		/*
		for(int k = 1 ; k <= 3 ; k++) {
			sort(club + 1 , club + n + 1 , cmp);
			int p = n / 2;
			for(int i = 1 ; p > 0 ; i++) {
				if(club[i].inl == k) {
					p--;
					ans += club[i].l;
					club[i].l = 0;
				}
			}
			int q = 2 * (sum[k] - n / 2);
			for(int i = 1 ; q > 0 ; i++) {
				if(club[i].inm = k) {
					club[i].l = club[i].m;
					club[i].inl = club[i].inm;
					q--;
				}
				if(club[i].ins = k) {
					club[i].s = club[i].m;
					club[i].ins = club[i].inm;
					q--;
				}
			}
			sum[1] = 0 ; sum[2] = 0 ; sum[3] = 0;
			for(int i = 1 ; i <= n ; i++) {
				sum[club[i].inl]++;
			}
		}
		*/
		sort(club + 1 , club + n + 1 , cmp);
		for(int i = 1 ; i <= n / 2 ; i++) {
			ans += club[i].l;
		}
		printf("%lld\n" , ans);
		ans = 0;
	}
	return 0;
}

