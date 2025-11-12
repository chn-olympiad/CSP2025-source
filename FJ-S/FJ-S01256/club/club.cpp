#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
namespace subtask1{
	int a[N][3],b[N],cnt[3];
	int n; ll res = 0;
	void init(){
		res = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		return ;
	}
	void check(int p){
		ll sum = 0;
		for (int i = 1;i <= n;++i){
			sum += a[i][p];
			int maxn = 0;
			for (int j = 0;j <= 2;++j)
			    if (j != p) maxn = max(maxn,a[i][j]);
			b[i] = a[i][p] - maxn;
		}
		sort(b + 1,b + n + 1);
		for (int i = 1;i <= n / 2;++i)
		    sum -= b[i];
		res = max(res,sum);
		return ;
	}
	void solve(){
		scanf("%d",&n);
		for (int i = 1;i <= n;++i){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		
		init();
		for (int i = 0;i <= 2;++i) check(i);
		
		ll sum = 0;
		for (int i = 1;i <= n;++i){
			int p = 0;
			for (int j = 1;j <= 2;++j)
			    if (a[i][j] > a[i][p]) p = j;
			sum += a[i][p]; cnt[p]++;
		}
		
		if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) res = max(res,sum);
		
		printf("%lld\n",res);
		return ;
	}
	void main(){
		int T; scanf("%d",&T);
		while (T--) solve();
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		
	subtask1 :: main();
	
	return 0;
}
