#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],rk=1;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a[1]);
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[1])rk++;
    }
    printf("%d ",(rk-1)/n+1);
    int x=rk%(2*n);
    if(x==0)printf("1");
    else if(x<=n)printf("%d",x);
    else printf("%d",2*n-x+1);
    return 0;
}
