#include<bits/stdc++.h>
using namespace std;
int m,n,a,seat[19][19],g[810];
/*
int cmp(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}*/
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&g[i]);
    }
    a=g[1];
    sort(g+1,g+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(g[i]==a){
            int c=(n*m+1-i+n-1)/n,r=(n*m+1-i)%n;
            if(r==0) r=n;
            if(c%2==0) r=n-r+1;
             printf("%d %d",c,r);
            break;
        }
    }
    return 0;
}
