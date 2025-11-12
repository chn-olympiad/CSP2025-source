#include<bits/stdc++.h>
#define RD read()
using namespace std;
int read(){
	int x = 0, f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';ch = getchar();}
	return x * f;
}
int n, a[3], tot3, ans;
vector<int> cnt[3];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = RD;
	while(T --){
		n = RD;
		ans = 0;
		cnt[1].clear();
		cnt[2].clear();
		cnt[3].clear();
		for(int i = 1;i <= n;++ i){
			a[1] = RD;a[2] = RD;a[3] = RD;
			if(a[1] >= a[2] && a[1] >= a[3]){
				cnt[1].push_back(a[1] - max(a[2], a[3]));
			}else if(a[2] >= a[1] && a[2] >= a[3]){
				cnt[2].push_back(a[2] - max(a[1], a[3]));
			}else if(a[3] >= a[2] && a[3] >= a[1]){
				cnt[3].push_back(a[3] - max(a[2], a[1]));
			}
			ans += max(a[1], max(a[2], a[3]));
		}
		if(cnt[1].size() > (n >> 1)){
			sort(cnt[1].begin(), cnt[1].end());
			int l = cnt[1].size() - (n>> 1);
			for(int i = 0;i < l;++ i){
				ans -= cnt[1][i];
			}
		}
		if(cnt[2].size() > (n >> 1)){
			sort(cnt[2].begin(), cnt[2].end());
			int l = cnt[2].size() - (n>> 1);
			for(int i = 0;i < l;++ i){
				ans -= cnt[2][i];
			}
		}
		if(cnt[3].size() > (n >> 1)){
			sort(cnt[3].begin(), cnt[3].end());
			int l = cnt[3].size() - (n>> 1);
			for(int i = 0;i < l;++ i){
				ans -= cnt[3][i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
