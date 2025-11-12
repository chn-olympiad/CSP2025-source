#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[5005] = {};
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int sum = 0;
    int maxn = 0;
    if(n == 3){
        for(int i = 1;i <= n;i++){
            sum += a[i];
            maxn = max(maxn,a[i]);
        }
        if(sum > maxn * 2){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    return 0;
}
