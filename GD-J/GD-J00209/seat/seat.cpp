#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[105], b[105];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) cin >> a[i];
	for (int i = 1; i <= n*m; i++) b[i] = a[i];
	sort(b + 1, b + n*m + 1, greater<int>());
	int x = 1;//小R的下标 
	while (b[x]!=a[1]) x++;
	int t = 1;
	int posx = 0, posy = 0;
	for (int i = 1; i <= m; i++){
		if (i % 2 != 0){
			for (int j = 1; j <= n; j++){
				if (t != x) t++;
				else{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else {
			for (int j = n; j >= 1; j--){
				if (t != x) t++;
				else{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
