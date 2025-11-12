#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,x,y;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            s=i;
            break;
        }
    }
    x=(s-1)/n+1;
    y=(s-1)%n+1;
    if(x%2==1){
        printf("%d %d",x,y);
    }
    else{
        printf("%d %d",x,n+1-y);
    }
    return 0;
}
