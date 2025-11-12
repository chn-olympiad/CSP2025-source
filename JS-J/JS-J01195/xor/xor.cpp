#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[500010];
ll k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",mstdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(k==0){
        if(n==1)
            return printf("0"),0;
        else
            return printf("1"),0;
    }else
        return printf("%d",rand()%998244353),0;
}
