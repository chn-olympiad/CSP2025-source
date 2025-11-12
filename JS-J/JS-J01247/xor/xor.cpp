#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],ans,vis[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        pre[i] = a[i] ^ pre[i-1];
    }
    for(int len = 1;len <= n;len++){
        for(int l = 1;l+len-1 <= n;l++){
            int r = l+len-1;
            int flag = 0;
            for(int i = l;i <= r;i++){
                if(vis[i] == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) continue;
            if((pre[r] ^ pre[l-1]) != k) continue;
            for(int i = l;i <= r;i++){
                vis[i] = 1;
            }
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
