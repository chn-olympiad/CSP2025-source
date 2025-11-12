#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >>n >> m;
    long long t= n*m;
    long long a[t];
    for (int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    long long x,y;
    int l = a[1];
    sort(a+1,a+t+1);
    int b;
    for (int i = 1;i <= t;i++){
        if (a[i] == l) b = t-i+1;
    }
    if (b%m == 1) x = b/m + 1;
    else x = b/m;
    if (x % 2 ==1){
        if (x-1==0) y = 2;
        else y = b - (x-1)*m;
    }
    else {
        y = m - b + (x-1)*m + 1;
    }
    cout << x << " " << y;
    return 0;
}
