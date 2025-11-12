#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 2 * 1e5 + 5;

int num[MAX_N];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int nu = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d", &num[i]);
        nu += num[i];
    }
    if(k == 0){
        int out = 0;
        while(nu % 2 != 1 && nu != 0){
            nu /= 2;
            out++;
        }
        cout << out;
        return 0;
    }
    cout << nu;
    return 0;
}
