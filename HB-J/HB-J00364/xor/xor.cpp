#include <cstdio>
#define ll long long
ll sumx[500050],k;
int n,cnt,minn=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        ll x;scanf("%lld",&x);
        sumx[i]=sumx[i-1]^x;
    }
    for(int i=1;i<=n;i++){
        for(int j=minn+1;j<=i;j++){
            ll x=sumx[i]^sumx[j-1];
            if(x==k){
                cnt++;
                minn=i;
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
