#include<bits/stdc++.h>
using namespace std;
int a[5500],ans,p[5500];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    p[1]=1;
    for(i=2;i<=n;i++){
        p[i]=2*p[i-1]+1;
        p[i]%=998244353;
    }
    sort(l+1,l+n+1);
    for(i=2;i<=n;i++){
        for(j=1;j<=i-2;j++){
            for(l=j+1;l<i;l++){
                if(a[l]+a[j]>a[i]){
                    ans+=p[i-l+1];
                    ans%=998244353;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
