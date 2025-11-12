#include<bits/stdc++.h>
using namespace std;
int s[19][19], a[156];
bool is(int x){
    if(x%2 == 0) return true;
    return false;
}
int main(){
    int n, m, cnt = 0;
    cin  >> n >> m;
    for(int i = 1; i <= n*m; i++){
        cin >> a[i];
        cnt =  a[1];
    }
    sort(a+1, a+n*m+1);
    int ans = 0;
    for(int i = m*n; i >= 1; i--){
        if(a[i] == cnt){
            ans = m*n - i + 1;
        }

    }
    int c, r;
    if(is(ans/n)){
        r = abs(n - (ans/n));
    }else{
        r = 1+(ans/n);
    }
    if(ans%n != 0){
        c = ans/n + 1;
    }else{
        c = ans/n;
    }

    cout << c << ' ' << r;
    return 0;
}
