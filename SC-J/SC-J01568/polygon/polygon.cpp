#include<bits/stdc++.h>
using namespace std;
int n;
int a[10010];
int maxn = -1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > maxn){
			maxn= a[i];
		}
	}
	if(n <= 3){
		if((a[1] + a[2] + a[3]) > (maxn * 2)){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}