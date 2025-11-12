#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[1000005];
    int n,k;
    cin >> n,k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] == k){
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
