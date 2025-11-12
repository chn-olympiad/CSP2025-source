#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,m,k,tot;
long long h[1000005];
long long ans,sum;
const int mod=998244353;

long long C(int nn,int mm){
    if(mm*2>nn) mm=nn-mm;
    long long res=1;
    for(int i=nn;i>=nn-mm+1;i--){
        res=res*i%mod;
    }
    for(int i=1;i<=mm;i++){
        res/=i;
    }
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);

    int all1=1;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i]!=1) all1=0;
        sum+=a[i];
    }
    if(n==3){
        sort(a+1,a+1+n);
        if(a[3]>=a[1]+a[2]) cout<<0<<'\n';
        else cout<<1<<'\n';
        return 0;
    }
    if(all1){
        for(int i=3;i<=n;i++){
            ans=(ans+C(n,i))%mod;
        }
        cout<<ans<<'\n';
        return 0;
    }
    stable_sort(a+1,a+1+n,greater<int>());
    // for(int i=1;i<=n;i++){
    //     h[i]=h[i-1]+a[i];
    // }

    return 0;
}
/*

*/
