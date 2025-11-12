#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[10010];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m,t=0;
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++){
        cin>>a[i];
    }
    LL x=a[1];
    sort(a+1,a+n*m+1,cmp);

    for(LL i=1;i<=m;i++){
        if(i&1){
            for(LL j=1;j<=n;j++){
                ++t;
                if(a[t]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(LL j=n;j>=1;j--){
                ++t;
                if(a[t]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }

        }
    }
    return 0;
}
