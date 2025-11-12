#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
void f(int &x,int &y){
    if(x==1 && y%2==0){
        y++;
    }else if(x==n && y%2==1){
        y++;
    }else if(y%2==1){
        x++;
    }else{
        x--;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=1,num=a[1];
    for(int i=1;i<=n*m;i++){
        if(num==r){
            printf("%d %d",y,x);
        }
        f(x,y);
        num=a[i+1];
    }
    return 0;
}
