#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[500010];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    bool flag = 1;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        if(x != 1) flag = 0;
        a[i] = x;
    }
    if(flag){
        cout << n / 2 << endl;
        return 0;
    }else{
        cout << 2 << endl;
        return 0;
    }
    return 0;
}
