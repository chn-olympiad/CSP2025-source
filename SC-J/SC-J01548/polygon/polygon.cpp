#include <bits/stdc++.h>
using namespace std;
int n , a[5005] , ans , maxnn;
void solve1(int x,int y){
	float sum = 1;
	while(y){
		sum *= 1.0*x/y;
		x--;
		y--;
	}
	ans += int(sum);
	ans = ans % 998244353;
	return;
}
void solve2(int sid , int sum  ,int cnt, int maxn){
	if( cnt == 0){
		if(sum > 2*maxn){
			ans++;
			ans = ans % 998244353;
		}
		return;
	}
	for(int i = sid+1 ; i <= n - cnt + 1; i++ ){
		solve2(i , sum+a[i]  ,cnt-1 ,max(maxn,a[i]));
	}
} 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i<= n ;i++){
		scanf("%d",&a[i]);
		maxnn = max(maxnn,a[i]);
	}
	if(n == 3){
		if(a[1]+a[2]+a[3] > maxnn*2)cout << 1;
		else cout << 0;
		return 0;
	}
	if(maxnn <= 1){
		for(int i = 3 ; i <= n ; i++ ){
			solve1(n,i);
		}
		cout << ans;
		return 0;
	}
	for(int i = 3 ; i <= n ; i++ )solve2(0 , 0 , i , 0);
	cout << ans;
	return 0;
} 