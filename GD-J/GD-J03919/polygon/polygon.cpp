#include<bits/stdc++.h>
using name space std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdin);
    int n;
    int maxa=0,ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        maxa=max(a[i],maxa);
    }
    if (a[0]+a[1]+a[2]>=maxa*2){
        ans=1;
    }
    printf("%d",ans);
    return 0;
}
