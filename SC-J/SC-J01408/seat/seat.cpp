#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, a[155];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n *m;i++) cin >> a[i];
	int x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int pos = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i] == x){
			pos = i;
			break;
		}
	}
	int i = (pos + n - 1) / n, j = pos % n;
	if(j == 0) j = n;
	if(i % 2){ 
		cout << i << " " << j; 
	}
	else cout << i<< " " << n - j + 1;
	
	return 0;
}