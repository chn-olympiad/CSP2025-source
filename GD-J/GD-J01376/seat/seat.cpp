#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int a[maxn];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> a[i];
	}
	int a1 = a[1];
	sort(a + 1 , a + 1 + n * m , cmp);
	int r , c;	
	r = c = 1;
	int ans = 1;
	while(a1 != a[ans]){
		if(c % 2 == 1){
			if(r == m){
				c++;
				r = m;
			}
			else{
				r++;
			}
		}
		else{
			if(r == 1){
				c++;
				r = 1;
			}
			else{
				r--;
			}
		}
		++ans;
	}
	cout << c << " " << r;
	return 0;
}
