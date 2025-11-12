#include <bits/stdc++.h>
using namespace std;
int n, m, score[105], a, num;
int main () {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n*m; i++) {
        cin >> score[i];
    }
    a=score[1];
    sort(score+1, score+n*m+1);
    for (int i=1; i<=n*m; i++) if (score[i]==a) {
        a=n*m-i+1;
        //cout << a << ' ' << i << ' ' <<endl;
        break;
    }
    cout << a/n+1 << ' ';
    if ((a/n+1)%2==1) cout << a%n;
    else cout << n-a%n;
    return 0;
}
