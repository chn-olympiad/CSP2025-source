#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p,t,a[1000010],x[20][20],k;
bool cmp(const ll &x,const ll &y){
    return x>y;
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n*m;i++){
        scanf("%lld",a+i);
    }
    p=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(ll i=1;i<=n*m;i++){
        if(a[i]==p) t=i;
    }
    k=1;
    for(ll i=1;i<=m;i++){
        if(i%2==0){
            for(ll j=n;j>=1;j--){
                x[i][j]=k;
                k++;
            }
        }
        else{
            for(ll j=1;j<=n;j++){
                x[i][j]=k;
                k++;
            }
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(x[i][j]==t){
                printf("%lld %lld",i,j);
            }
        }
    }
    return 0;
}

