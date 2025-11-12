#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100; 
int n, m;
int a[N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int s = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int p = 0, c, r;
	for(int i = 1; i <= m; i++){
		if(i % 2 != 0){
			for(int j = 1; j <= n; j++){
				p++;
				if(a[p] == s){
					c = i;
					r = j;	
				}
			}	
		}
		else{
			for(int j = n; j >= 1; j--){
				p++;
				if(a[p] == s){
					c = i;
					r = j;
				}
			}	
		}
	}
	cout << c << " " << r;
	return 0;	
}
