#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E5 + 5;
int a[MAXN];


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == 1){
        if(a[1] == k){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    if(n == 2){
        int cnt(0);
        if(a[1] == k){
            cnt++;
        }
        if(a[2] == k){
            cnt++;
        }
        if(a[1] ^ a[2] == k){
            cnt++;
        }
        cout << cnt;
        return 0;
    }
    cout << 1;
    return 0;
}
