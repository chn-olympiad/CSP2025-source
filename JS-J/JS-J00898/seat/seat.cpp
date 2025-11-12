#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],s[15][15],xr,x,y,k,h;
bool fg;
bool cmp(long long q,long long p){
    return q>p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    xr=a[1];
    sort(a+1,a+n*m+1,cmp);
    x=1,y=1,k=0,h=1;
    s[x][y]=a[++k];
    while(a[k]>xr){
       fg=0;
       if(fg==0&&y%2==0&&x==1){
             s[x][++y]=a[++k];
             h=1;
             fg=1;
        }
        if(fg==0&&y%2==1&&x==n){
            s[x][++y]=a[++k];
            h=-1;
            fg=1;
        }
        if(fg==0){
            s[x+h][y]=a[++k];
            x+=h;
        }
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}
