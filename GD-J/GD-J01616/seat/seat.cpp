#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 110;
int n, m;

struct pii{
	int x, id;
	
	bool operator < (const pii & o) const{
		return x > o.x;
	}
} a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n*m);
	int x;
	for(int i = 1; i <= n*m; i++){
		if(a[i].id == 1){
			x = i;
			break;
		}
	}
	int h = (x-1)/n+1;
	cout << h << ' ' << ((h&1) ? (x-1)%n+1 : m-(x-1)%n);
	return 0;
}
