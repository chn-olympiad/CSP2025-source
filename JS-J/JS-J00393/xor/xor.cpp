#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
long long a[500010],c[500010];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    c[0]=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        c[i]=c[i-1]^a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            if((c[r]^c[l-1])==k){
                l=r;
                ans++;
                break;
            }
        }
    }
    printf("%d",ans);
}
