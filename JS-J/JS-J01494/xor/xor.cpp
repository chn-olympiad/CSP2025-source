#include <iostream>
#define maxn 500005
using namespace std;

int n, k, ans;
int a[maxn], sum[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) sum[i]=sum[i-1]^a[i];
    int t=1;
    for(int j=t; j<=n; j++){	
        for(int i=t; i<=j; i++){
            if((sum[j]^sum[i-1])==k){
                ans++;
                // cout << i << ' ' << j << endl;
                t=j+1;
                i=n+1;
            }
        }
    }
    cout << ans;
    return 0;
}
