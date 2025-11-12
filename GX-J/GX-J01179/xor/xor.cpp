#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
int f[N][N],a[N];
struct node{
    int l,r;
}e[N * N];int m;

int sums[N];
bool cmp(node x,node y){
    if (x.r != y.r) return x.r < y.r;
    return x.l > y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
		cin >> a[i];
		f[i][i] = a[i];
		if (f[i][i] == k){
			++m;
			e[m].l = i,e[m].r = i;
		}
    }
    sums[1] = a[1];
    for (int i = 2; i <= n; ++i){
		sums[i] = (sums[i - 1] ^ a[i]);
    }
    for (int len = 2; len <= n; ++len){
		for (int l = 1; l + len - 1 <= n; ++l){
			int r = l + len - 1;
			f[l][r] = sums[r] ^ sums[l - 1];
			if (f[l][r] == k){
			++m;
			e[m].l = l,e[m].r = r;
			}
		}
    }
    sort(e + 1,e + 1 + m,cmp);
    int now = -1;
    for (int i = 1; i <= m; ++i){
		if (now < e[i].l){
			++ans;
			now = e[i].r;
		}
    }
    cout << ans;
    return 0;
}
