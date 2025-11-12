#include <bits/stdc++.h>
using namespace std;
int a[500005];
int sum[500005];
int n;
int ans;
int k;
int minn;
int now;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1]^a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = minn; j < i; j++){
            now = sum[i]^sum[j];
            if(now == k){
                minn = i;
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
//QWQ 60pts
