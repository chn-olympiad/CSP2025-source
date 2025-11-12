#include <cstdio>
int m,n,mn=0,g;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m,&n);
    scanf("%d",&g);
    for(int i=2;i<=m*n;i++){
        int x;scanf("%d",&x);
        if(x>g) mn++;
    }
    printf("%d %d",mn/n+1,(mn/n)%2==1?n-mn%n:(mn+n)%n+1);
    return 0;
}
