#include <bits/stdc++.h>
using namespace std;
bool cmp(int q, int w){
    return q > w;
}
int s[15][15];
int x = 2, y = 1, a1, p = 2;
int a[105];
bool t;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    a1 = a[1];
    sort(a + 1, a + n * m + 1, cmp);
	s[1][1] = a[1];
	if (a[1] == a1){
		cout << 1 << " " << 1;
		return 0;
	}
    while (x >= 1 && x <= n && y >= 1 && y <= m){
        if (x == 1 && t == 0){
            s[x][y] = a[p++];
            if (s[x][y] == a1) break;
            x = 1;
            y++;
            t = 1;
            continue;
        }
        if (x == n && t == 0){
            s[x][y] = a[p++];
            if (s[x][y] == a1) break;
            x = n;
            y++;
            t = 1;
            continue;
        }
        if (y % 2 == 1){
            s[x][y] = a[p++];
            if (s[x][y] == a1) break;
            x++;
            t = 0;
            continue;
        }
        if (y % 2 == 0){
            s[x][y] = a[p++];
            if (s[x][y] == a1) break;
            x--;
            t = 0;
            continue;
       }
    }
    cout << y << " "<< x;
    return 0;
}
