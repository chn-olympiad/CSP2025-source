#include <cstdio>
#include <algorithm>
using namespace std;

int n , a[100005][3];

pair <int , int> tmp[3];
void getmax(int b[3]){
	tmp[0] = make_pair(b[0] , 0);
	tmp[1] = make_pair(b[1] , 1);
	tmp[2] = make_pair(b[2] , 2);
	sort(tmp , tmp + 3);
}

int cnt[3] , qwq[100005] , awa[100005] , twt[100005] , ans;
void solve(){
	cnt[0] = cnt[1] = cnt[2] = 0;
	ans = 0;
	scanf("%d" , &n);
	for(int i = 1;i <= n;i++) scanf("%d%d%d" , &a[i][0] , &a[i][1] , &a[i][2]);
	for(int i = 1;i <= n;i++){
		getmax(a[i]);
		cnt[tmp[2].second]++;
		qwq[i] = tmp[2].first - tmp[1].first;
		ans += tmp[2].first;
		awa[i] = tmp[2].second;
	}
	getmax(cnt);
	int maxn = tmp[2].first;
	const int N = (n >> 1);
	if(maxn <= N){ printf("%d\n" , ans); return ; }
	int tot = 0;
	for(int i = 1;i <= n;i++) if(tmp[2].second == awa[i])
		twt[++tot] = qwq[i];
	sort(twt + 1 , twt + 1 + tot);
	maxn -= N;
	for(int i = 1;i <= maxn;i++) ans -= twt[i];
	printf("%d\n" , ans);
}

int main(void){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
//	freopen("club5.in" , "r" , stdin);
	int T; scanf("%d" , &T);
	while(T--) solve();
	return 0;
}
