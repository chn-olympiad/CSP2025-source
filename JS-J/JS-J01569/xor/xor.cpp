#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt;
int last = -1;
int a[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == k){
            cnt++;
            last = i;
        }
        else{
            int p = a[i];
            for(int j = i - 1; j > last; j--){
                p = p ^ a[j];
                if(p == k){
                    cnt++;
                    last = i;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
