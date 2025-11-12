#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[105], fs;
bool pd = 0;
bool cmp(int t1, int t2){
	return t1 > t2;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	fs = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int x = 0, y = 1;
	for(int i = 1;i <= n * m;i++){
		if(pd == 0){
			if(x + 1 <= n) x++;
			else x = n, y++, pd = 1;
		} else{
			if(x - 1 >= 1) x--;
			else x = 1, y++, pd = 0;
		}
		if(a[i] == fs){
			cout << y << " " << x; 
		}
	}
	return 0;
}
/*
2 5
5 9 10 4 3 6 7 8 1 2 91 78
*/
