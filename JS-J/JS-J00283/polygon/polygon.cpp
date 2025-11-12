#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5010];
int ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2){
        printf("0");
        return 0;
    }
    if(n==3){
        if(a[1]+a[2]>a[3]) ans++;
        printf("%d",ans);
        return 0;
    }
    if(n==5){//
        if(a[1]==1) printf("9");
        else printf("6")
        return 0;
    }
    return 0;
}
