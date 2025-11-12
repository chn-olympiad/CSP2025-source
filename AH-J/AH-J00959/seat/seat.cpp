#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int r,w;
int x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++ i)
        cin >> a[i];
    r = a[1];
    sort(a + 1,a + n * m + 1);
    for(int i = 1; i <= n * m; ++ i)
        if(a[i] == r)w = n * m - i + 1;
    x = ceil(double(w) / double(n));
    y = (w - 1) % n + 1;
    if(x % 2 == 0) y = n - y + 1;
    cout <<x <<' ' <<y;
    return 0;
}
