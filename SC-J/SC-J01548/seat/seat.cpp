#include <bits/stdc++.h>
using namespace std;
int n , m , a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	int sid = 1;
	for(int i = 2 ; i <= n*m ; i++ ){
		cin >> a[i];
		if(a[i] > a[1]){
			sid++;
		}
	}
	int cnt = 1;
	while(sid > m ){
		sid -= m ;
		cnt++;
	}
	if(cnt % 2 == 1){
		cout << cnt  <<" "<< sid ;
	}
	else cout << cnt  <<" "<< m - sid + 1;
	return 0;
} 