#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500010],t=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int r=1;r<=n;r++){
        int num=0;
        for(int l=r;l>t;l--){
            num^=a[l];
            if(num==k){
                ans++;
                t=r;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
