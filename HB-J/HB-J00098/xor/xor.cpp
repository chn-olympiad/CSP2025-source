#include <bits/stdc++.h>
using namespace std;
int g[500005];
int ans[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        g[i]=g[i-1]^x;
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=0;j<i;j++){
            num=0;
            if((g[i]^g[j])==k) num=1;
            ans[i]=max(ans[j]+num,ans[i]);
        }
    }
    cout << ans[n];
    return 0;
}
