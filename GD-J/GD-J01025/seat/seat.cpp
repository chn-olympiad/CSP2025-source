#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 1e6 + 10;
bool cmp(i64 x , i64 y){
	return x > y;
}
int mian(){
	i64 n , m;
	cin >> n >> m;
	vector<i64>a(n * m + 10 , -1);
	for(int i = 1 ; i <= n * m ; i ++){
		cin >> a[i];
	}
	i64 tsk = a[1];
	sort(a.begin() + 1 , a.begin() + n * m + 1 , cmp);
//	for(int i = 1 ; i <= n * m ; i ++)cout << a[i] << ' ';
	vector<vector<i64> > mp(n + 10 , vector<i64>(m + 10 , -1));
	i64 idx = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(i & 1){
			for(int j = 1 ; j <= m ; j++)mp[j][i] = a[++idx];
		}
		else {
			for(int j = m ; j >= 1 ; j--)mp[j][i] = a[++idx];
		}
	}
	
	for(int i = 1 ; i<= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(mp[i][j] == tsk){
				cout << j << ' '<< i;
				break; 
			}
//			cout << mp[i][j] <<' ';
		} 
//		cout << '\n';
	}
	return 0;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--){
		mian();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

