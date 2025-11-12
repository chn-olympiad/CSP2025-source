#include<bits/stdc++.h>
using namespace std;
int n,m,num=0,a,sco,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&sco);
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a);
        if(a>sco) num++;
    }
    for(int i=1;i<=num;i++){
        if(x==n&&y%2==1) y++;
        else if(x==1&&y%2==0) y++;
        else if(y%2==1) x++;
        else x--;
    }
    printf("%d %d",y,x);
    return 0;
}
