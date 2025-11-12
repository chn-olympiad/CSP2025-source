#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=15;
bool cmp(const ll &x,const ll &y){
    return x>y;
}
ll n,m,a[N*N],R,k,p;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
        if(i==1) R=a[i];
    }
    k=n*m;
    sort(a+1,a+k+1,cmp);
    for(ll i=1;i<=k;i++){
        if(a[i]==R) p=i;
    }
    ll i=1,j=1,tot=1;
    while(i<=n&&j<=n){
        if(tot==p){printf("%lld %lld",j,i);return 0;}
        if(j%2==1){
            if(i==n) j++;
            else i++;
        }
        else if(j%2==0){
            if(i==1) j++;
            else i--;
        }
        tot++;
    }
    return 0;
}
