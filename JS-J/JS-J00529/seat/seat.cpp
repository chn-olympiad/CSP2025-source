#include <iostream>
#include <cstdio>
using namespace std;
int m,n;int little_r,mingci,r_lie,r_hang;
int xiangshangquyu(int beichushu,int chushu){
    return beichushu/chushu+(beichushu%chushu!=0);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&little_r);
    for(int i=2;i<=n*m;i++){
        int x;
        scanf("%d",&x);
        if(x>little_r)mingci++;
    }
    mingci++;
    r_lie=xiangshangquyu(mingci,n);
    if(r_lie&1)r_hang=(mingci%n==0?n:mingci%n);
    else r_hang=n+1-(mingci%n==0?n:mingci%n);
    printf("%d %d",r_lie,r_hang);
    return 0;
}
