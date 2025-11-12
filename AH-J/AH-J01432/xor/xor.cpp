#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[500010],sum[500010],d[500010],n,k,maxn,p,l,r;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    if(n<=10000){
       for(LL i=1;i<=n;i++){
            for(LL j=1;j<=i;j++){
                d[i]=max(d[i],d[j-1]+((sum[i]^sum[j-1])==k));
            }
        }
        cout<<d[n];
    }
    else{
        for(LL i=1;i<=n;i++){
            bool flag=false;
            for(LL j=l;j<=r;j++){
                if((sum[i]^sum[j])==k){
                    flag=true;
                    break;
                }
            }
            d[i]=max(d[i],d[i-1]+flag);
            if(d[i]>d[i-1]){
                l=i,r=i;
            }
            else{
                r=i;
            }
        }
        cout<<d[n];
    }

    return 0;
}
