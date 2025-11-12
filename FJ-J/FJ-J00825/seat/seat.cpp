#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N], map1[15][15];
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, cnt=0;
	cin >> n >> m;
	cnt = n*m;
	for(int i=1; i<=cnt; i++) {
		cin >> a[i];
	}
	int score = a[1];
	sort(a+1, a+1+cnt);
	int i=1, j=1, l=cnt, p=1, flag=0;

	while(l >= 1) {
		if(i > n) {
			i = n;
			j += 1;
			p = -1;
			flag = 1;
			map1[i][j] = a[l];
			if(map1[i][j] == score) {
				cout << j << " " << i;
				return 0;
			}
		} else if(i < 1) {
			i = 1;
			j += 1;
			p = 1;
			flag = 1;
			map1[i][j] = a[l];
			if(map1[i][j] == score) {
				cout << j << " " << i;
				return 0;
			}
		} else {
			if(i == 1 && j == 1) {
				map1[i][j] = a[l];
				if(map1[i][j] == score) {
					cout << j << " " << i;
					return 0;
				}
				i += p;
			} else {
				if(flag == 1) {
					i += p;
					if(i>= 1 && i <=n )	{
						map1[i][j] = a[l];
						if(map1[i][j] == score) {
							cout << j << " " << i;
							return 0;
						}
					}

					else {
						l +=1;
					}

				} else {
					map1[i][j] = a[l];
					if(map1[i][j] == score) {
						cout << j << " " << i;
						return 0;
					}
					i += p;
				}
			}
		}
		l --;

	}

	return 0;
}
