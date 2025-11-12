#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=110;
LL a[N],ans;
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL x=n*m;
    for(LL i=1;i<=n*m;i++) cin>>a[i];
    LL R=a[1];
    sort(a+1,a+1+n,cmp);
    for(LL i=1;i<=n*m;i++){
        if(a[i]==R) ans=a[i];
    }
    if(ans==a[1]){
            cout<<1<<" "<<1;
            return 0;
    }
    if(ans%n*m==0){
        cout<<n<<" "<<m;
        return 0;
    }
    else{
        cout<<ans%n<<" "<<ans%m+1;
    }
    return 0;
}
