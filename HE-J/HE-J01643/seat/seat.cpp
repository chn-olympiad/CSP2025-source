#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int l[1000], m, n, x;
    cin >> n >> m;
    int s = n*m;
    for(int i = 1;i <= s;i++){
        cin >> l[i];
    }x = l[1];
    sort(l+1, l+s+1, greater<int>());
    for(int i = 1;i <= s;i++){
        if(l[i] == x){
            x = i;
            break;
        }
    }int a = x%n==0? n:x%n, b = ceil((float)x/n);
    if(!b%2) a = n-a;
    cout << b << ' ' << a;
    return 0;
}
