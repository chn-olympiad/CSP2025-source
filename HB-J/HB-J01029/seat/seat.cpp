#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int ned;
int gett;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n*m; i++){
        cin >> a[i];
        if(i == 1) ned = a[i];
    }
    sort(a+1,a+n*m+1);
    reverse(1+a,a+n*m+1);
    for(int i = 1; i <= n*m; i++){
        if(a[i] == ned){
            gett = i;
            break;
        }
    }
    cout << ned << ' ' << gett << '\n';
    if(((gett-1)/n)%2 == 1) cout << (int)ceil((double)gett/n) << ' ' << n-(gett%n)+1;  //from right
    else cout << (int)ceil((double)gett/n) << ' ' << (gett == n ? n : gett%n);  // from left
    return 0;
}
//QWQ 100pts
