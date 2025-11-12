// oh oh oh
// easy T2
// it's more easy than 2024 CSP-J T2 !
// but I don't know can i AC !
// check in 9:48 : no wrong things
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, sc[100100], man, i, r, c;
bool cmp(int x, int y) {return x > y;}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> sc[(i - 1) * m + j];
    man = sc[1];
    sort(sc + 1, sc + n * m + 1, cmp);

    for(i = 1, r = 1, c = 1; sc[i] != man; i++) {
        if(c % 2 == 1) {
            if(r == n) c++;
            else r++;
        } else {
            if(r == 1) c++;
            else r--;
        }
    }
    cout << c << " " << r << endl;
    return 0;
}