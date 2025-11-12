#include<bits/stdc++.h>
using namespace std;
int t, n;
int a1[10000], a2[10000], a3[10000];
bool cpp(const int a const int b){
    return a > b;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a1[i] >> a2[i] >> a3[i];
        }
        sort(a1 + 1, a1 + n, cpp);
        sort(a2 + 1, a2 + n, cpp);
        sort(a3 + 1, a3 + n, cpp);
    }

    return 0;
}
