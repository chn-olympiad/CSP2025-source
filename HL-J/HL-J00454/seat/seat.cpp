#include<bits/stdc++.h>
using namespace std;
int n , m ;
int a[110];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m ;
	int t = n * m;
	for(int i = 1 ; i <= t ; i++){
		cin >> a[i];
	}
	int t1 = a[1] ;
	sort(a + 1 , a + t + 1);
	int seat = 0 ;
	for(int i = t ; i > 0 ; i--){
		if(a[i] == t1){
			seat = t - i + 1 ;
		}
	}
	int ans1 = 0 , ans2 = 0 ;
	if(seat % n > 0){
		ans1 = seat/n + 1;
	}else{
		ans1 = seat/n;		
	}
	if(ans1 % 2 == 1){
		if(seat % n == 0){
			ans2 = n ;
		}else{
			ans2 = seat % n ;
		}
	}else{
		if(seat % n == 0){
			ans2 = 1 ;
		}else{
			ans2 = n - seat % n + 1 ;
		}
	}
	cout << ans1 << ' ' << ans2 << endl ;
	return 0 ;
}
