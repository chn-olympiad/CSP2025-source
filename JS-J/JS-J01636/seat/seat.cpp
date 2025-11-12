#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int score[105];
int ms,nb;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    p=n*m;
    scanf("%d",&ms);
    for(int i=2;i<=p;i++){
        int t;
        scanf("%d",&t);
        if(t>ms)++nb;
    }
    ++nb;

    int group=(nb-1)/(2*m),id=nb%(n),lr=(nb)%(2*m);
    //cerr<<group<<' '<<id<<' '<<lr<<endl;
    if(id==0)id=n;
    if(lr>m||(lr==m&&n==1)){
        printf("%d %d",group*2+2,n+1-id);
    }else{
        printf("%d %d",group*2+1,id);
    }
    return 0;
}
