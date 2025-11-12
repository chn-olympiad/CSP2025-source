#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, id, tot, ans, cnt[3], p[N], bel[N], a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>t;
	while(t --){
		cin>>n, id = -1, tot = ans = cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1;i <= n;i = -~i){
			int ma = 0;
			for(int j = 0;j <= 2;j = -~j){
				cin>>a[i][j];
				if(a[i][ma] < a[i][j]) ma = j;
			}
			ans += a[i][ma], bel[i] = ma, cnt[ma] ++;
		}
		for(int i = 0;i <= 2;i = -~i) if(cnt[i] > (n >> 1)) id = i;
		if(id != -1){
			for(int i = 1;i <= n;i = -~i){
				if(bel[i] != id) continue;
				p[++tot] = a[i][id];
				for(int j = 0;j <= 2;j = -~j) if(j != id) p[tot] = min(p[tot], a[i][id] - a[i][j]); 
			}
			sort(p + 1, p + 1 + tot);
			for(int i = 1;i <= cnt[id] - (n >> 1);i = -~i) ans -= p[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
