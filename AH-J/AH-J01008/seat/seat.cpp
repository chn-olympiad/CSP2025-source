#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    LL x=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    LL p=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            p=i;
            break;
        }
    }
    LL l=(p+n-1)/n;
    LL h=p-(l-1)*n;
    if(l%2==0){
        h=n+1-h;
    }
    printf("%lld %lld",l,h);
    return 0;
}
