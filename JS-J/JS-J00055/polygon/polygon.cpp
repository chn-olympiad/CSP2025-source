#include<bits/stdc++.h>
using namespace std;

int num[50005];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
    }
    if(n == 3){
        if(num[1] + num[2] > num[3] && num[2] + num[3] > num[1] && num[1] + num[3] > num[2]){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        long long out = 0;
        for(int i = n - 2;i >= 1;i--){
            out += i * (i + 1) / 2;
            out %= 998244353;
        }
        cout << out;
    }
    return 0;
}
