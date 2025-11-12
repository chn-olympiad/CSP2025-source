#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
int n, m;
bool cmp(int a, int b){
	return a > b;
}
pair<int, int> next(pair<int, int> x){
	if(x.second % 2 == 1){
		if(x.first == n)return {x.first, x.second + 1};
		else return {x.first + 1, x.second}; 
	}
	else {
		if(x.first == 1)return {x.first, x.second + 1};
		else return {x.first - 1, x.second};
	}
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	pair<int, int>place = {1, 1};
	for(int i = 1; i <= n * m; i++){
		if(a[i] == k){
			break;
		}
		place = next(place);
	}
	cout  << place.second << " " << place.first << endl;
}
