#include<bits/stdc++.h>
using namespace std;
int m,n,R,a[105],wei,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&R);
    a[1]=R;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        wei++;
        if(a[i]==R)break;
    }
    if(wei%n==0){
        if((wei/n)%2==0){
            printf("%d 1",wei/n);
        }
        else printf("%d %d",wei/n,n);
    }
    else{
        if((wei/n)%2==0){
            printf("%d %d",wei/n+1,wei%n);
        }
        else printf("%d %d",wei/n+1,n-wei%n+1);
    }
    return 0;
}