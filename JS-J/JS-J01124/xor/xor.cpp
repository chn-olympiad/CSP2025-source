#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
const int M = 1e4 + 10;
int re[M];
int n,k;
int ans = 0;
struct node{
    int l,r;
}flag[M];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int cnt = 0;

    for(int l = 1;l <= n;l++){
        for(int r = l;r <= n;r++){
            bool s = true;
            for(int k = 1;k <= cnt;k++){
                if(l <= flag[k].r || r <= flag[k].r){
                    s = false;
                }
            }
            if(s == false){
                continue;
            }
            int sum = a[l];
            for(int i = l + 1;i <= r;i++){
                sum = sum ^ a[i];
            }
            if(sum == k){
                ans++;
                flag[++cnt].l = l;
                flag[++cnt].r = r;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

