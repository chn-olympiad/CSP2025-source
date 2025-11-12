#include<bits/stdc++.h>
using namespace std;

int num[110];
int n, m, temp, Index, flag;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> num[i];
	}
	temp = num[1];
	sort(num + 1, num + 1 + n * m, cmp);
	for(int i = 1; i <= m; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= n; j++) {
				Index++;
				if(num[Index] == temp) {
					cout << i << ' ' << j;
					flag = 1;
					break;
				}
			}
		}
		else {
			for(int j = n; j >= 1; j--) {
				Index++;
				if(num[Index] == temp) {
					cout << i << ' ' << j;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1) {
			break;
		}
	}
	return 0;
}
