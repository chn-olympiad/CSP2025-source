#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.in","r",stdin);
    int n,m,a[111],c,r,f,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        f=a[1];
    }
    while(n*m){
        for(int i=2;i<=n*m;i++){
            if(a[i]>a[i-1]){
                int l=a[i-1];
                a[i-1]=a[i];
                a[i]=l;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==f){
            x=i;
            break;
        }
    }
    if(x%n==0) c=x/n;
     else c=x/n+1;
    r=x%n;
    if(c%2==0) r=n-r;
    printf("%d %d",c,r);
    return 0;
}
