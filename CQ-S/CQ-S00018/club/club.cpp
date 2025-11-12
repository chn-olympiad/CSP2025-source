#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	const int MAXN = 100005;
	int a[MAXN][3], bel[MAXN];
	struct D{
		int id, v;
	}b[MAXN << 1];
	bool cmp(D a, D b){
		return a.v < b.v;
	}
	int t[MAXN];
	int main(){
		int T;
		scanf("%d", &T);
		while(T--){
			int n;
			scanf("%d", &n);
			int c0 = 0, c1 = 0, c2 = 0;
			int ans = 0;
			for(int i = 1;i <= n;i++){
				scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
				//先把所有人都放到它最大的里面去 
				int Max = max(max(a[i][0], a[i][1]), a[i][2]);
				ans += Max;
				if(Max == a[i][0]){
					c0++;
					bel[i] = 0;
				} 
				else if(Max == a[i][1]){
					c1++;
					bel[i] = 1;
				}
				else{
					c2++;
					bel[i] = 2;
				}
			}
			int sz = max(max(c0, c1), c2);
			//不需要调整了 
			if(sz <= n / 2){
				printf("%d\n", ans);
			}
			//把多余的人调走，这里可以贪心拿变化量小的 
			else{
				int num = 0;
				if(c0 == sz){
					for(int i = 1;i <= n;i++){
						if(bel[i] == 0){
							b[++num] = (D){i, a[i][0] - a[i][1]};
							b[++num] = (D){i, a[i][0] - a[i][2]};
						}
					}
				} 
				else if(c1 == sz){
					for(int i = 1;i <= n;i++){
						if(bel[i] == 1){
							b[++num] = (D){i, a[i][1] - a[i][0]};
							b[++num] = (D){i, a[i][1] - a[i][2]};
						}
					}
				}
				else{
					for(int i = 1;i <= n;i++){
						if(bel[i] == 2){
							b[++num] = (D){i, a[i][2] - a[i][0]};
							b[++num] = (D){i, a[i][2] - a[i][1]};
						}
					}
				}
				sort(b + 1, b + num + 1, cmp);
				int it = 1;
				for(int i = 1;i <= sz - n / 2;i++){
					while(t[b[it].id]) it++;
					t[b[it].id] = 1;
					ans -= b[it].v;
				}
				printf("%d\n", ans);
			}
			//多测清空 
			for(int i = 1;i <= n;i++) t[i] = 0;
		}
//		while(1);
		return 0;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return Luo_ty::main();
}//Chelsea 2012
//4MB
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
