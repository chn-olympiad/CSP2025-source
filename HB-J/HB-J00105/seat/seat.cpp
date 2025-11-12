#include <bits/stdc++.h>
using namespace std;
bool cmp(int n, int m){
    return n > m;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int a[n * m + 10];
    for(int i = 1; i <= n * m;i++){
        cin >> a[i];
    }
    int x = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int p;
    for(int i = 1;i <= n * m;i++)
        if(a[i] == x)
            p = i;
    int c , r;
    if(p > n && p / n * n == p){
        c = p / n;
    }
    else if(p <= n){
        c = 1;
    }
    else{
        c = p / n + 1;
    }
    if(c % 2 == 0)
        r = p % n + c / 2;
    else{
        r = p % (2 * n);
    }
    cout << c << " " << r;
    return 0;
}
