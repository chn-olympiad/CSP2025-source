#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 5e5 + 10;
i64 a[N][4]{};i64 n ;
void solve1(){
	vector<i64>tmp;
	for(int i = 1 ;i <= n ; i++)tmp.push_back(a[i][1]);
	sort(tmp.rbegin() , tmp.rend());
	i64 ans = 0;
	for(int i = 0 ; i < n / 2 ; i++)ans += tmp[i];
	cout << ans ;
	return ;
}
i64 ans = 0;
void dfs(i64 x , i64 c1 , i64 c2 , i64 c3 , i64 sum){
	if(x > n){
		ans = max(ans , sum);
	}
//	cout << x << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << sum <<'\n';
	if(c1 < n / 2)dfs(x + 1 , c1 + 1 , c2 , c3 , sum + a[x][1]);
	if(c2 < n / 2)dfs(x + 1 , c1 , c2 + 1 , c3 , sum + a[x][2]);
	if(c3 < n / 2)dfs(x + 1 , c1 , c2 , c3 + 1 , sum + a[x][3]); 
}
int mian(){
	cin >> n;
	memset(a , 0 , sizeof a);
	for(int i = 1 ; i <= n ; i ++){
		cin >>a[i][1] >> a[i][2] >> a[i][3]; 
	}
	ans = 0;
	
	i64 sum2 = 0 , sum3 = 0;
	for(int i = 1 ; i <= n ; i++)sum2 += a[i][2];
	for(int i = 1 ; i <= n ; i++)sum3 += a[i][3];
	if(sum2 == 0 && sum3 == 0){
		solve1();
		return 0;
	} 
//	if(sum2 == 0){
////		solve2();
//	}
	else dfs(1 , 0 , 0 , 0 , 0);
	cout << ans <<'\n';
	return 0;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	i64 t;
	cin >> t;
	while(t--)mian();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

