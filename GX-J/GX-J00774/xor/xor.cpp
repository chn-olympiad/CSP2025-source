#include<bits/stdc++.h>
using namespace std;
int n,a[555555];
long long k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k=0){
        if(n<=100){
            cout<<n/2;
            return 0;
        }
    }
    return 0;
}
