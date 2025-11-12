#include<bits/stdc++.h>
using namespace std;
int a[5010],n,ans = 0;
bool x = true;
void f(int cnt , int m , int dp , int k){
	if(dp > n + 1) return;
	if(cnt > 2 * m && k >= 3 && x){
		ans++;
		ans %= 998244353;
	}
	x = true;
	f(cnt + a[dp] , max(m , a[dp]) , dp + 1 , k + 1); 
	x = false;
	f(cnt , m , dp + 1 , k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	f(0 , 1 , 1 , 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
