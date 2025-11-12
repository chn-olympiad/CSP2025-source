#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[105];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n*m;i++) cin>>a[i];
    LL x=a[1];
    sort(a+1,a+n*m+1,cmp);
    LL y=1;
    for(LL i=1;i<=m;i++){
        if(i%2==0){
            for(LL j=n;j>=1;j--){
                if(x==a[y]){
                    cout<<i<<' '<<j;
                    return 0;
                }
                else y++;
            }
        }
        else{
            for(LL j=1;j<=n;j++){
                if(x==a[y]){
                    cout<<i<<' '<<j;
                    return 0;
                }
                else y++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
