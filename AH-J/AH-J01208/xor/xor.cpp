#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000050],mk,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=0) mk=1;
    }
    if(mk==0){
        if(k==0){
            printf("%d",n);
        }else if(k==1){
            printf("0");
        }
    }else if(mk==1){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
            }
            printf("%d",ans);
        }else if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
            printf("%d",ans);
        }
    }
    return 0;
}
