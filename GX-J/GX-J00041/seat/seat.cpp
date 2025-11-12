#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ll n,m,xm,vis;
    scanf("%lld %lld",&n,&m);
    ll t=n*m;
    ll a[t+5];
    for(int i=1;i<=t;i++){
        scanf("%lld",&a[i]);
        if(i==1)xm=a[i];
    }
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++){
        if(a[i]==xm)vis=i;
    }
    ll cnt=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                if(a[cnt]==xm){
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
            }
        }else{
            for(int j=1;j<=m;j++){
                if(a[cnt]==xm){
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
            }

        }
    }


    return 0;
}
