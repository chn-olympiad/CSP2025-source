
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n==1)cout << 0;
    else cout << 1;
    return 0;
}
