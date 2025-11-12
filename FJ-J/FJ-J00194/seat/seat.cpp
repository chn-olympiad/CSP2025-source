#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n, m;
int a[maxn * maxn];

void read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)){
		if (c == '-'){
			f = 1;
		}
		c = getchar();
	}
	while (isdigit(c)){
		x = x * 10 + c - 48;
		c = getchar();
	}
	x *= f;
}

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n * m; ++i){
		read(a[i]);
	}
	int val = a[1];
	sort(a + 1, a + n * m + 1, cmp);	
	int id = 0;
	for (int i = 1; i <= n * m; ++i){
		if (a[i] == val){
			id = i;
			break;
		}
	}
	int lie;
	lie = id / n;
	lie++;
	if (id % n == 0){
		lie--;
	}
	id -= (lie - 1) * n;
	if (lie % n == 1){
		if (id == 0){
			id = n;
		}
		cout << lie << " " << id;
	}
	else{
		if (id == 0){
			id = n;
		}
		cout << lie << " " <<  (n - id + 1);
	}
	return 0;
}
