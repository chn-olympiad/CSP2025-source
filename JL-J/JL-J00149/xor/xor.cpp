#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,i,j,s=0,ans=0;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=b[i-1]^a[i];
    }
    for(i=1;i<=n;i++){
        for(j=s;j<i;j++){
            if(j<s) continue;
            if(k==(b[i]^b[j])){
                ans++;
                s=i;
                //cout<<i<<' '<<j<<' '<<s<<endl;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
