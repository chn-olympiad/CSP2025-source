#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0;
    if(k == 0){
        for(int i = 1;i <= n;i++){
            if(a[i] != 0){
                continue;
            }
            ans++;
        }
        cout << ans;
    }
    return 0;
}