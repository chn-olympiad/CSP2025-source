#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000];
bool cmp(int x, int y){
	return x > y;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)cin >> a[i];
	int score = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1;
	for(i = 1; i <= n * m; i++){
		if(a[i] == score)break;
	}
	int hang = i % n, lie = i / n;
	if(hang)lie++;
	cout << lie << " ";
	if(lie % 2 == 1){
		if(hang == 0)cout << n;
		else cout << hang;
	}else{
		if(hang == 0)cout << 0;
		else cout << n - hang + 1;
	}
	return 0;
} 
