#include<bits/stdc++.h>
using namespace std;

int n,m,u[105],o=1,p;

bool cmp(int a,int b){
    return a>b;
}

int main(void){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&u[i]);
    }
    p=u[1];
    sort(u+1,u+1+(n*m),cmp);
    for(int i=1;i<=n*m;i++){
        if(u[i]==p){
            p=i;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            o++;
            if(o==p){
                if(i%2==0){
                    int g=n-j+1;
                    cout<<i<<" "<<g;
                    return 0;
                }
                else{
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
