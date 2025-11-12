#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s=1,s_=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=n;i>=3;i--){
        s_*=i;
        s_%=998244353;
    }
    s=n*(n-1)/2;
    s+=n;
    printf("%d",(s_-s)%998244353);
    return 0;
}
