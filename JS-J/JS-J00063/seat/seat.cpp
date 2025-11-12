#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11],b[105],t,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&b[i]);
    }
    t=b[1];
    sort(b+1,b+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(b[i]==t){
            t=i;
            break;
        }
    }
    c=(t+n-1)/n;
    t-=(c-1)*n;
    if(c%2==1)r=t;
    else r=n-t+1;
    printf("%d %d",c,r);
}
