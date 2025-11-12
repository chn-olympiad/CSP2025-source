#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k;
int a[N];
int s = 1, l = 1;
bool h = 0;
int cmp(int x, int y) {
	return x > y;
}int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m ; i++) {
        cin >> a[i];
    }k = a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == k) {
            cout << s << " " << l;
            return 0;
        }if(h == 0 && l < n) {
            l++;
        }else if(h == 0 && l == n) {
            s++;
            h = 1;
        }else if(h == 1 && l > 1) {
            l--;
        }else if(h == 1 && l == 1) {
            s++;
            h = 0;
        }
    }return 0;
}/*
4 5
12 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16 17 18 19 20
*/
