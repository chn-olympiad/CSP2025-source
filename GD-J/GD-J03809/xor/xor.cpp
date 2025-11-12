#include<bits/stdc++.h>
using namespace std;
long long ans , sum[100005] , len , n , m , a[100005];
struct node{
	int l , r;
}l_r[100005];
bool cmp(node x , node y){
	if(x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = (sum[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if((sum[j] ^ sum[i - 1]) == m){
				l_r[len].l = i , l_r[len++].r = j;
			}
		}
	}
	if(!len) cout << 0;
	else{
		sort(l_r , l_r + len , cmp);
		int last = l_r[0].r;
		ans++;
		for(int i = 1; i < len; i++){
			if(l_r[i].l > last){
				ans++ , last = l_r[i].r;
			}
		}
		cout << ans;
	}
	return 0;
}

