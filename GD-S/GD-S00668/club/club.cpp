#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1e5+7;
typedef struct{
	int sat[4];
} mem;
mem a[N];
vector<mem>clb[4]; 
int flg;
//inline bool cmp1(mem n, mem m){
//	return n.sat[1] < m.sat[1];
//}
//inline bool cmp2(mem n, mem m){
//	return n.sat[2] < m.sat[2];
//}
//inline bool cmp3(mem n, mem m){
//	return n.sat[3] < m.sat[3];
//}
inline int calc(mem n){
	int x = flg%3+1;
	int y = (flg+1)%3+1;
	x = n.sat[flg]-n.sat[x];
	y = n.sat[flg]-n.sat[y];
	return min(x, y);
}
inline bool cmp(mem n, mem m){
	return calc(n) < calc(m);
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%lld", &t);
	while(t--){
		for(int i = 1; i <= 3; i++)
			clb[i].clear();
		int n;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				scanf("%lld", &a[i].sat[j]);
		for(int i = 1; i <= n; i++){
			int mx = 0;
			for(int j = 1; j <= 3; j++)
				if(a[i].sat[j] >= a[i].sat[mx])
					mx = j;
			clb[mx].push_back(a[i]);
		}
		flg = 0;
		for(int i = 1; i <= 3; i++)
			if(clb[i].size() > n/2){
				flg = i;
				break;
			} 
		int ans = 0;
		for(int i = 1; i <= 3; i++)
			for(auto j : clb[i])
				 ans += j.sat[i];
		if(!flg){
			printf("%lld\n", ans);
			continue;
		}
		sort(clb[flg].begin(), clb[flg].end(), cmp); 
//		sort(clb[1].begin(), clb[1].end(), cmp1);
//		sort(clb[2].begin(), clb[2].end(), cmp2);
//		sort(clb[3].begin(), clb[3].end(), cmp3);
//		for(int i = 1; i <= 3; i++)
//			for(auto j : clb[i])
//				printf("%d ", j.sat[i]); 
		for(int i = 0; i < clb[flg].size()-n/2; i++)
			ans -= calc(clb[flg][i]);
		printf("%lld\n", ans);
	}
	return 0; 
} 
