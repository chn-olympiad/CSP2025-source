#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],s,mp[11][11],k;
bool cmp(int x,int y){
    return x>y;
}
void d(int x,int y,int z){
    if(a[k+1]==s){
        cout<<y<<" "<<x;
        return;
    }
    if(z==0){
        mp[x][y]=a[++k];
        if(x+1<=n)d(x+1,y,0);else d(x,y+1,1);
    }else{
        mp[x][y]=a[++k];
        if(x-1>0)d(x-1,y,1);else d(x,y+1,0);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    d(1,1,0);
    return 0;
}
