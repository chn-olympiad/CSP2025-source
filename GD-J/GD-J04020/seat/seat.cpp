#include<bits/stdc++.h>
#define ll long long
#define N 1007
using namespace std;
int n, m;
int v[N];
int cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> v[i];
	}
	int a = v[1];
	sort(v + 1, v + n * m + 1, cmp);
	int p;
	for(int i = 1;i <= n * m;i++){
		if(v[i] == a){
			p = i;
			break;
		}
	}
	int c, r;
	c = (p - 1) / m + 1;
	if(c % 2 == 1){
		r = (p - 1) % m + 1;
	}
	else{
		r = m - (p - 1) % m;
	}
	cout << c << ' ' << r << '\n';
	return 0;
}
