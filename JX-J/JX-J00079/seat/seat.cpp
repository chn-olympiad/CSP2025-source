#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
ll n,m,a[maxn],cnt,x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    int b=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            cnt=n*m-i+1;
            break;
        }
    }
    while(1){
        if(cnt>n){
            cnt-=n;
            x++;
        }
        else{
            if(cnt==n) printf("%lld %lld",x,cnt);
            else{
                printf("%lld %lld",x+1,cnt);
            }
            break;
        }
    }
    printf("\n");
    return 0;
}

