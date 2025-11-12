#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m , a[105],b,d,c,r;
    cin >> n >> m;
    for (int i = 1 ; i <= n * m; i++){
        cin >> a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1 ; i <= n*m;i++){
        if(a[i] == b){
            d = i;
            break;
        }
    }
    if(d % n == 0){
        c = d / n;
        if (c % 2 == 1) r = n;
        else r = 1;
    }
    else{
        c = d / n + 1;
        if (c % 2 == 1) r = d % n;
        else r = n - d % n + 1;
    }
    cout << c << " " << r;
    return 0;
}
