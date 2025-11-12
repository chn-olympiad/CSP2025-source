#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            p=a[i];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1,dir=1;
    for(int i=1;i<=n*m;i++){
        if(p==a[i]){
            printf("%d %d",y,x);
            return 0;
        }
        int dx=x+dir;
        if(dx>=1&&dx<=n){
            x=dx;
        }else{
            y++;
            dir=0-dir;
        }
    }
    return 0;
}
