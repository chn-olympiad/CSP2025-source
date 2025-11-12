#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105],r,c,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    c=m*n;
    for(int i=1;i<=c;i++){
        scanf("%d",&a[i]);
    }
    r=a[1];
    sort(a+1,a+c+1);
    for(int i=1;i<=c;i++){
        if(r==a[i]){
            r=c-i+1;
            break;
        }
    }
    c=r/n;
    y=r%n;
    if(y!=0){
        if(c%2==0)  printf("%d %d",c+1,y);
        else printf("%d %d",c+1,n-y+1);
    }
    else {
        if(c%2==0) printf("%d 1",c);
        else printf("%d %d",c,n);
    }

    return 0;
}
