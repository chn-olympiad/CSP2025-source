#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],ans,now;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i]=f[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>now;j--){
            int m=f[i]^f[j-1];
            if(m==k){
                ans++;
                now=i;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
