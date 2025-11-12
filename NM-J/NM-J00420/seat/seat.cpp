#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[105] = {0},b,c;
    cin >> n >> m;
    for(int i = 0;i<n*m;i++) cin >> a[i];
    b = a[0];
    sort(a,a+(m*n),greater<int>());
    for(int i = 0;i<n*m;i++){
        if(a[i]==b){
            c = i+1;
            break;
        }
    }
    int d = c/n+bool(c%n);
    cout << d << " ";
    if(d%2==1){
        if(c%n==0)cout << n;
        else cout << c%n;
    }else cout << n-c%n+1;
    return 0;
}