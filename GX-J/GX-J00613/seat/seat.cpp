#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n , m;
    cin>>n>>m;

    int p = n * m;
    int a[1000001];
    for(int i = 1; i <= p; i++){
        cin>>a[i];
    }
    int R = a[1];

    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= p; j++){
            if(a[j+1] > a[j]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    int Rr;
    for(int i = 1; i <= p; i++){
        if(a[i] == R){
            Rr = i;
            break;
        }
    }
    int sm, sn, t = Rr;
    while(Rr > n){
        Rr -= n;
    }
    sn = Rr;
    Rr = t;

    if(Rr % n == 0) sm = Rr / n;
    else sm = Rr / n + 1;

    cout<<sm<<' '<<sn;

    return 0;
}
