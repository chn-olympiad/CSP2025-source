#include<bits/stdc++.h>
using namespace std;

int num[105];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, me;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> num[i];
    }
    me = num[1];
    sort(num + 1, num + n * m + 1, cmp);
    int l = 0, h = 1;
    while(l < m){
        for(;h <= n;h++){
            if(num[l * n + h] == me){
                cout << l + 1 << " " << h;
                return 0;
            }
        }
        l++;
        h = 1;
        for(;h <= n;h++){
            if(num[l * n + h] == me){
                cout << l + 1 << " " << n - h + 1;
                return 0;
            }
        }
        l++;
        h = 1;
    }
    return 0;
}
