#include<bits/stdc++.h>
using namespace std;
int n , m , a[1005] , sum;
bool cmp(int a , int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout); 
	cin >> n >> m;
	cin >> a[1];
	sum = a[1];
	for(int i = 2; i <= n * m; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n * m , cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == sum){
			int ans_ , ans;
			ans_ =  (i - 1) / n + 1;
			cout << ans_ << " ";
			if(ans_ & 1){
				if(!(i % n)){
					cout << n;
				}else{
					cout << i % n;
				}
			}else{
				if(!(i % n)){
					cout << 1;
				}else{
					cout << n - i % n + 1;
				}
			}
		}
	}
	return 0;
}

