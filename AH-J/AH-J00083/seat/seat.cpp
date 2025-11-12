#include<bits/stdc++.h>

using namespace std;

int n,m,t[101],w;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&t[i]);
    }
    w=t[1];
    sort(t+1,t+n*m+1,cmp);
    int x=0,y=1,flag=0;
    for(int i=1;i<=n*m;i++){
        if(flag==0&&x!=n){
            x++;
        }else if(flag==1&&x!=1){
            x--;
        }else if(x==n&&flag==0){
            y++;
            flag=1;
        }else{
            y++;
            flag=0;
        }
        if(t[i]==w){
            printf("%d %d",y,x);
            break;
        }
    }
    return 0;
}
