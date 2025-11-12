#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
const int INF = 0x3f3f3f;
const int N = 1e5 + 10;
#define LL long long

int n , m , a[110];

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	int cnt = 1;
	for(int i = 1 ; i <= n * m ; i++){
		scanf("%d" , &a[i]);
		if(a[i] > a[1]) cnt++;
	}
	if(cnt % n == 0) {
		cout << cnt / n << " ";
		if((cnt / n) % 2 == 1) cout << n;
		else cout << 1;
	}else {
		cout << cnt / n + 1 << " ";
		if((cnt / n + 1) % 2 == 1) cout << cnt % n;
		else cout << n - (cnt % n) + 1;	
	}
	return 0;
}

/*
3 3
93 95 96 94 98 99 100 97 92


*/
