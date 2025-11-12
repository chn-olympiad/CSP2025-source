#include<bits/stdc++.h>
using namespace std;
long long a[12][12] , x[110] , t = 1;
bool f = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m , s , r , c , p;
	cin >> n >> m;
	for(int i = 1 ; i <= n*m ; i++){
		cin >> s;
		x[i] = s;
		if(i == 1) r = s;
	}
	sort(x + 1 , x + n*m + 1 , greater<int>());
	for(int i = 1 ; i <= m ; i++){
		if(i % 2 == 1){
			for(int j = 1 ; j <= n ; j++){
				a[j][i] = x[t];
				if(x[t] == r){
					c = j;
					p = i;
					f = 1;
					break;
				} 
				t++;
			}
		}else{
			for(int j = n ; j >= 1 ; j--){
				a[j][i] = x[t];
				if(x[t] == r){
					c = j;
					p = i;
					f = 1;
					break;
				}
				t++;
			} 
		}
		if(f == 1){
			cout << p << ' '  << c;
			break;
		}
	}
	return 0;
}