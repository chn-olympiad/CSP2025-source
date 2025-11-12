#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+5;
int n,m,x,a[maxn];
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m,j=1;i>=1;i--,j++){
        if(a[i]==x){
            x=j;
            break;
        }
    }
    if(((x-1)/n+1)%2==1){
        printf("%lld %lld",(x-1)/n+1,(x-1)%n+1);
    }
    if(((x-1)/n+1)%2==0){
        printf("%lld %lld",(x-1)/n+1,n-(x-1)%n);
    }
    return 0;
}
