#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int tot=n*m;
    for(int i=1;i<=tot;i++) scanf("%d",&a[i]);
    int pos=a[1];
    sort(a+1,a+tot+1,cmp);
    int rk=0;
    for(int i=1;i<=tot;i++){
        if(a[i]==pos){
            rk=i;
            break;
        }
    }
    if(rk%n==0) c=rk/n;
    else c=rk/n+1;
    if(c%2==1) r=rk%n;
    else r=(n-rk%n+1)%n;
    if(r==0) r=n;
    printf("%d %d",c,r);
    return 0;
}
