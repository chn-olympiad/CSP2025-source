#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node{
	int best,las_best,id1,id2;
	bool operator < (const node &b){
		return (b.best-b.las_best) < (best-las_best);
	}
};
int T,n;
node g[N];
int a[10];
int cnt[10];
void work(){
	int res=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int mx=0;
		int lmx=0;
		for(int j=1;j<=3;j++){
			cin >> a[j];
			if(a[j] > mx){
				lmx = mx;
				mx = a[j];
				g[i].id2=g[i].id1;
				g[i].id1 = j;
			}else if(a[j] > lmx){
				lmx = a[j];
				g[i].id2 = j;
			}
			g[i].best = mx;
			g[i].las_best = lmx;	
			cnt[j] = 0;
		}
	}
	sort(g+1,g+n+1);
	for(int i=1;i<=n;i++){
//		cout << g[i].las_best << ' ' << g[i].best << ' ' << g[i].id1 << '\n';
		if(cnt[g[i].id1] >= n/2){
			res+=g[i].las_best;
			cnt[g[i].id2]++;
		}else{
			res+=g[i].best;
			cnt[g[i].id1]++;
		}
	}
	cout << res << '\n';
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		work();
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
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
