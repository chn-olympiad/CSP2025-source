#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[205];
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n ,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n*m; ++i)
        scanf("%d",&a[i]);

    int R=a[1];
    sort(&a[1],&a[n*m+1],f);

    int i=1;
    for( ; i<=n*m; ++i){
        if(a[i]==R)
            break;
    }


    if(i%n)
        printf("%d ",i/n+1);
    else
        printf("%d ",i/n);

    if((i/n)&1)
        printf("%d",(i%n ? n-i%n+1:n));
    else
        printf("%d",(i%n ? i%n:1));
    return 0;
}
