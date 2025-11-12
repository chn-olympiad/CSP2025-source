#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0,m = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] == 0&&k == 0){
            ans++;
        }else if(a[i] == 1&&k == 1){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
