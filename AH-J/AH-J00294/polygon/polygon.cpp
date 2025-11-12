//polygon.cpp
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],n;
long long ans,x1,x2;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a[i]);
    for(int i=1;i<=n-2;i++)
        for(int j=i+2;j<=n;j++){
            for(int k=i;k<=j;k++){
                x1+=a[k];
                x2=max(x2,a[k]);
            }
        if(x1>x2*2) ans++;
        x1=x2=0;
    }
    printf("%lld\n",ans%998244353);
    return 0;
}
