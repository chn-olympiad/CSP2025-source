#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 5e3 + 10 , Mod = 998244353;
i64 n , ans = 0 , a[N];
map<vector<PIL> , i64>mp;
void DFS(i64 x , i64 cnt , i64 sum , i64 pre , vector<PIL>cho){
	if(x > n + 1)return;
	if(cnt >= 3 && sum > 2 * pre && pre != -1 && !mp[cho]){
		ans ++;
		mp[cho] = 1;
//		for(auto [cur , idx] : cho)cout <<cur<<' ';cout << '\n';
	}
	
	
	
	cho.push_back({a[x] , x});
	DFS(x + 1 , cnt + 1 , sum + a[x] , max(a[x] , pre),cho);
	cho.pop_back();
	DFS(x + 1 , cnt , sum , pre , cho);
}
int mian(){	
	cin >> n;
	for(int i = 1 ; i <= n ; i++)scanf("%lld" , &a[i]);
//	sort(a + 1 , a + n + 1);
	vector<PIL>cho;
	DFS(1 , 0 , 0 , -1 , cho);
	cout << ans % Mod;
	return 0;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--){
		mian();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

