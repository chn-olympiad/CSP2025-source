#include<bits/stdc++.h>
using namespace std;
int a[110];
bool mycmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,xiao,xia;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    xiao=a[1];
    sort(a+1,a+m*n+1,mycmp);
    for(int i=1;i<=m*n;i++){
        if(a[i]==xiao){
            xia=i;
            break;
        }
    }
    int xx=xia%(2*n);
    if(xx==0){
        xx=1;
    }
    if(xx>n){
        xx-=n;
        xx=n-xx+1;
    }

    int yy=xia/n;
    if(xia%n!=0){
        yy++;
    }
    cout<<yy<<' '<<xx;
    return 0;
}
