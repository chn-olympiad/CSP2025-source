#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5 + 10;
int a[N];
int cnt = 0,cnt1 = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(k == 0 && n > 2){
        for(int i=1;i<n;i++){
            if(a[i] == 1 && a[i+1] == 1){
                i++;
                cnt++;
            }
            if(a[i] == 0) cnt1++;
        }
        cout << cnt + cnt1;
    }else if(k == 0 && n <= 2){
        if(a[n] == 0 || a[n-1] == 0) cout << 1;
        else cout << 0;
    }else if(k == 1){
        for(int i=1;i<=n;i++){
            if(a[i] == 1) cnt++;
        }
        cout << cnt;
    }
    return 0;
}
