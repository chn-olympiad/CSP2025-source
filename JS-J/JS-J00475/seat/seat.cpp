#include<bits/stdc++.h>
using namespace std;
int n,m,x,ran=1,sc,han,lie,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&x);
        if(i==1)sc=x;
        if(i!=1&&x>sc)ran++;
    }
    lie=ceil(ran/n);
    if(ran%n==0)t=n;
    else t=ran%n,lie++;
    if(lie%2==0)han=n-t+1;
    else han=t;
    printf("%d %d",lie,han);
    return 0;
}
