#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],l=1;
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x[i]=(x[i-1]^a[i]);
    }
    for(int r=1;r<=n;r++){
        if(l<=r){
            int f=(x[r]^x[l-1]);
            if(f==k){
                ans++;
                l=r+1;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
