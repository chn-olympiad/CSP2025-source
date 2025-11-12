#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n, m, k, from, to, w, ans = -1;
struct kode{
	int from, to, w;
	bool operator <(const kode &x) const
	{
		return x.w < w;
	}
};
int krr[100005], wrr[30][10005], arr[30], bc[100005];
priority_queue <kode> lrr;

void cx(int now){
	if(bc[now] == now){
		return ;
	}
	cx(bc[now]);
	bc[now] = bc[bc[now]];
}
void zc(priority_queue <kode> frr){
	int sum = 0, js = n; 
	for(int i = 1; i <= n + k; i++){
		bc[i] = i;
	}
	for(int i = 1; i <= k; i++){
		if(krr[i] == 1){
			sum = sum + arr[i];
			js++;
		}
	}
	if(sum >= ans && ans != -1){
		return ;
	}
	while(frr.size()){
		if(js == 1){
			break;
		}
		if(sum >= ans && ans != -1){
			return ;
		}
		int fx = frr.top().from, fy = frr.top().to, kx = frr.top().w;
		frr.pop();
		if(fx > n && krr[fx - n] == 0){
			continue;
		}
		if(fy > n && krr[fy - n] == 0){
			continue;
		}
		cx(fx);
		cx(fy);
		if(bc[fx] == bc[fy]){
			continue;
		}
		else{
			sum = sum + kx;
			bc[bc[fx]] = bc[fy];
			js--;
		}
	}
	if(ans == -1){
		ans = sum;
	}
	ans = min(ans, sum);
}
void ss(int now){
	if(now >= k + 1){
		zc(lrr);
		return ;
	}
	ss(now + 1);
	krr[now] = 1;
	ss(now + 1);
	krr[now] = 0;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &from, &to, &w); 
		lrr.push({from, to, w});
	}
	for(int i = 1; i <= k; i++){
		scanf("%lld", &arr[i]);
		for(int j = 1; j <= n; j++){
			scanf("%lld", &wrr[i][j]);
			lrr.push({n + i, j, wrr[i][j]});
		}
	}
	ss(1);
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
