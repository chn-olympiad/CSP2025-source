#include<bits/stdc++.h>
using namespace std;

int n,m,mine,x,y,a[101],sum;



int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&mine);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n*m-1;i++){
        scanf("%d",&x);
        a[x]++;
    }
    sum=0;
    for(int i=100;i>mine;i--){
        sum+=a[i];
    }
    x=1;y=1;
    for(int i=1;i<=sum;i++){
        if(y==n){
            x++;
            y=1;
        }
        else{
            y++;
        }
    }
    if(x%2==0)y=n-y+1;
    printf("%d %d\n",x,y);
    return 0;
}
