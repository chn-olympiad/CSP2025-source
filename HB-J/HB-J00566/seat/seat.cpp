#include<bits/stdc++.h>
using namespace std;
int a[15][15],a1[150];
int m,n,f,x,y,ai;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++){
        scanf("%d",&a1[i]);
    }
    ai=a1[0];
    x=n-1;
    if(x%2){
        y=0;
    }
    else{
        y=m-1;
    }
    sort(a1,a1+m*n);
    //for(int i=0;i<n*m;i++){
    //    printf("%d ",a1[i]);
    //}
    for(int i=0;i<m*n;i++){
        a[y][x]=a1[i];
        //printf("x:%d y:%d\n",x,y);
        //for(int j=0;j<n;j++){
        //    for(int k=0;k<m;k++){
        //        printf("%d ",a[j][k]);
        //    }
        //    printf("\n");
        //}
        //printf("\n");
        if(a1[i]==ai){
            printf("%d %d",x+1,y+1);
            break;
        }
        if(x%2==0){
            if(y==0){
                x--;
            }
            else{
                y--;
            }
        }
        else{
            if(y==n-1){
                x--;
            }
            else{
                y++;
            }
        }
    }
    return 0;
}
