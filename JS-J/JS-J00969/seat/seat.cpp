#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
    int t=a[1];
    sort(a+1,a+n*m+1);
    int cnt=n*m;
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++){
                if(a[cnt--]==t){
                    printf("%d %d",j,i);
                    return 0;
                }
            }
        }else{
            for(int i=n;i>=1;i--){
                if(a[cnt--]==t){
                    printf("%d %d",j,i);
                    return 0;
                }
            }
        }
    }
}
