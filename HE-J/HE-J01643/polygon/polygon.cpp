#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in", "r", stdin);
    //freopen("polygon.out", "w", stdout);
    int n, l[10000], max_ = 0;
    long long ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> l[i];
        max_ = max(l[i], max_);
    }if(n < 3){
        cout << 0;
        return 0;
    }
    for(int i = 3;i <= n;i++){
        vector<int>x(i+1);
        for(int j = 1;j <= i;j ++){
            x[j] = j;
        }
        while(x[i] <= n){
            for(int j = 1;j <= i;j++){
                cout << x[j] << ' ';
            }cout << endl;
            for(int j = i;j > 0;j--){
                if(++x[j] <= n-(i.-j)) break;
                else x[j] = x[j-1]+2;
            }
        }
    }
    return 0;
}
