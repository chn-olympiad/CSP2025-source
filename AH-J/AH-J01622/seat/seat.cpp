#include<bits/stdc++.h>
using namespace std;
int n,m,a[111111],d[111][111];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int p=a[1],j=1,s;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(j%2==0){
           if(i%n==0) s=1;
            else s=n-i%n+1;
        }
        else {
            if(i%n==0) s=n;
            else s=i%n;
        }
        if(a[i]==p){
            printf("%d %d",j,s);
            return 0;
        }
        if(i%n==0){
            d[s][j]=a[i];
            j++;
        }else d[s][j]=a[i];
    }
    return 0;
}
