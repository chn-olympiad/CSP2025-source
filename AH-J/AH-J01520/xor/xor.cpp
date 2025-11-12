#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long sum[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sum[1] = a[1];
    sum[0] = 0;
    for(int i = 2;i<=n;i++){
        sum[i] = sum[i-1]^a[i];
    }
    long long ans = 0;
    long long left = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] == k){
            left = i;
            ans++;
            continue;
        }
        long long other = sum[i]^k;
        for(int j = left;j<i;j++){
            if(sum[j] == other){
                left = i;
                ans++;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
