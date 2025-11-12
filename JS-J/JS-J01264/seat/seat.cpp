#include <bits/stdc++.h>
using namespace std;
int a,b,r = 1,n,m,x,y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> a;
    for (int i = 1;i <= n * m - 1;i++)
    {
        cin >> b;
        if (b > a) r++;
    }
    if (r % n == 0){
        x = r / n;
        if (x % 2 == 0) y = 1;
        else y = n;
    }
    else{
        x = r / n + 1;
        if (x % 2 == 0) y = n - x % n;
        else y = x % n;
    }
    cout << x << " " << y;
    return 0;
}
