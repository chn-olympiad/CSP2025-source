#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1])c+=1;
    }
    c+=1;
    if(c%n){
        x=c/n+1;
        if(x%2)y=c%n;
        else y=n-(c%n)+1;
    }else{
        x=c/n;
        if(x%2)y=n;
        else y=1;
    }
    printf("%d %d",x,y);
    return 0;
}
