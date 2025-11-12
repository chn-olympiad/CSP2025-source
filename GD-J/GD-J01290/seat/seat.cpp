#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, m;
LL a[1000100];
int cmp(LL a, LL b){
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(LL i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	LL r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	LL pos = 0;
	for(LL i = 1; i <= n * m; i++){
		if(a[i] == r){
			pos = i;
			break;
		}
	}
	
	LL p = pos / n;
	if(pos % n == 0){
		cout << p << " ";
		p -= 1;
	}else{
		cout << p + 1 << " ";
	}
	if(p % 2 == 0){
		cout << pos - p * n;
	}else{
		cout << n - (pos - p * n);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
