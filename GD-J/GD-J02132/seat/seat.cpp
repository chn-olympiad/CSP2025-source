#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n,m,l[105],r,cnt;
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n*m; i++)
        cin >> l[i];
    r=l[0];
    sort(l, l+n*m, cmp);
    for(int i = 0; i < n*m; i++)
        if(l[i] == r){
            cnt=i;
            break;
        }
    cout << cnt/n+1 << ' ';
    if((cnt/n) % 2 == 0)
        cout << cnt%n+1;
    else
        cout << n-cnt%n;
}
