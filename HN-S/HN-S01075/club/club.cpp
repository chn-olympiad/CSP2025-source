#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t , n , a[N][3] , cnt[3] , maxn;
void dfs(int x , int sum){
	if(x > n){
		maxn = max(maxn , sum);
		return;
	}
	if(cnt[0] < n / 2){
		cnt[0]++;
		dfs(x + 1 , sum + a[x][0]);
		cnt[0]--;
	}
	if(cnt[1] < n / 2){
		cnt[1]++;
		dfs(x + 1 , sum + a[x][1]);
		cnt[1]--;
	}
	if(cnt[2] < n / 2){
		cnt[2]++;
		dfs(x + 1 , sum + a[x][2]);
		cnt[2]--;
	}
}
struct node{
	int a , b , c;
	bool operator<(const node &x)const{
		if(max({a , b , c}) != max({x.a , x.b , x.c}))return max({a , b , c}) > max({x.a , x.b , x.c});
		int now = max({a , b , c}) , now2 = max({x.a , x.b , x.c});
		if(now == a)now = max(b , c);
		if(now == b)now = max(a , c);
		if(now == c)now = max(a , b);
		if(now2 == x.a)now2 = max(x.b , x.c);
		if(now2 == x.b)now2 = max(x.a , x.c);
		if(now2 == x.c)now2 = max(x.a , x.b);
		if(now != now2)return now > now2;
		return min({a , b , c}) > min({a , b , c});
	}
}d[N];
int now[N];
void sol(){
	cin >> n;
	int tot = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	bool flag = false;
	for(int i = 1;i <= n;i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		if(a[i][1] || a[i][2] || (!a[i][0]))flag = true;
		now[i] = a[i][0];
	}
	for(int i = 1;i <= n;i++)d[i] = {a[i][0] , a[i][1] , a[i][2]};
	if(!flag){
		sort(now + 1 , now + n + 1);
		int sum = 0;
		for(int i = n;i >= n / 2;i--){
			sum += now[i];
		}
		cout << sum << '\n';
		return;
	}
	maxn = 0;
	dfs(1 , 0);
	cout << maxn << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)sol();
	return 0;
}
