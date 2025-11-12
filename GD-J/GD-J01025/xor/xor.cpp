#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 5e5 + 10;
int mian(){
	i64 n , k;
	cin >> n >> k;
	vector<i64>a(n + 10 , 0);
	for(int i = 1 ; i <= n ; i++)scanf("%lld" , &a[i]);
//	for(int i = 1 ; i <= n ; i++)cout << a[i] << ' ';
	
	vector<i64>Pre;
	Pre = a;
	for(int i = 2 ; i <= n ; i++)Pre[i] ^= Pre[i - 1];
	vector<PIL>res;//区间[i , j]异或和为k
	//区间越短越好，以每一个点为左端点找最近的符合条件的右端点 
	for(int l = 1 ; l <= n ; l++){
		i64 r = l;
		while((Pre[r] ^ Pre[l - 1] )!= k && r <= n){
			r ++;
//			cout <<l << ' '<<r << ' ' << (Pre[r] ^ Pre[l - 1]) <<'\n';
		}
		if(r > n)continue;//没有可以的
		res.push_back({l , r}); 
	}
	sort(res.begin() , res.end());
//	for(auto[l , r] : res)cout << l <<' '<<r <<'\n';
	vector<i64>cnt(n + 10 , 0);//以i为起点最大区间数 
	for(int i = 0 ; i < res.size() ; i++){
		auto [l , r] = res[i];
		cnt[l] ++;
		
		i64 tmp = i + 1;
		
		while(r <= n && tmp <= n){
			auto [nl , nr] = res[tmp++];
			if(nl > n || nr > n)break;
			if(nl > r){
//				cout << l <<' ' << r << ' ' << nl << ' '<<nr<<'\n'; 
				l = nl , r = nr , cnt[res[i].first]++;
				
			}
		}
	}
	i64 ans = 0;
//	cout <<'\n';
//	for(int i = 1 ; i <= n ; i++)cout<<cnt[i]<<' '; 
	for(int i = 1 ; i <= n ; i++)ans = max(ans , cnt[i]);
	cout << ans ;
	return 0;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--){
		mian();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

