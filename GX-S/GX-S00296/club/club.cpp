#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T , n;
int bk[5];
struct node{
	int v[5];
	int d , ind;
}c[N];
struct ss{
	int val , id;
};
bool cmp(ss p , ss q){
	if(p.val != q.val)
		return p.val > q.val;
	return p.id < q.id;
}
bool cmp1(node p , node q){
	return p.d < q.d;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	vector<node> ch[4];
	ss a[5];
	for(int ff = 1 ; ff <= T ; ++ff){
		cin >> n;
		memset(bk , 0 , sizeof bk);
		long long ans = 0;
		for(int i = 1 ; i <= 4 ; ++i) ch[i].clear();
		for(int i = 1 ; i <= n ; ++i){
			a[0].id = 1 , a[1].id = 2 , a[2].id = 3;
			cin >> a[0].val >> a[1].val >> a[2].val;
			c[i].v[1] = a[0].val , c[i].v[2] = a[1].val , c[i].v[3] = a[2].val;
			sort(a , a + 3 , cmp);
			c[i].d = a[0].val - a[1].val; c[i].ind = a[1].id;
			ch[a[0].id].push_back(c[i]);
			bk[a[0].id]++; ans += a[0].val;
		}
		for(int i = 1 ; i <= 3 ; ++i){
			if(bk[i] > n / 2){
				sort(ch[i].begin() , ch[i].end() , cmp1);
				for(auto it : ch[i]){
					int oth = 6 - it.ind;
					if(bk[i] <= n / 2) break;
					if(bk[it.ind] < n / 2){
						if(it.d == it.v[i] - it.v[oth]){
							ans -= it.d;
							bk[i]--;
							if(bk[oth] <= bk[it.ind]) bk[oth]++;
							else bk[it.ind]++;
						}else{
							ans -= it.d;
							bk[i]-- , bk[it.ind]++;
						}
					}else{
						ans -= it.d;
						bk[i]-- , bk[oth]++;
					}
				}
				break;
			}
		}
		cout << ans << '\n';
	}
    exit(0);
}
