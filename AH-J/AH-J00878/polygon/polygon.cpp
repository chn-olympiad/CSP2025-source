#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, l[100001] , qh = 0 , maxn = INT_MIN , cnt = 0;
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(LL i = 1 ; i <= n ; i++){
		cin >> l[i];
		qh += l[i];
		maxn = max(maxn , l[i]);
	} 
	if(2 * maxn < qh){
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
