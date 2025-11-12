#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p,o=0,u=0;
bool cmp(int x,int y){
    return x>y;
}
void laoda(int x,int y,int h){
    if(o==1){
        return;
    }
    if(a[h]==p){
        cout<<y<<" "<<x;
        o=1;
        return;
    }
    if(u==0){
        if(x==n){
            u=1;
            laoda(x,y+1,h+1);
        }else{
            laoda(x+1,y,h+1);
        }
    }else{
        if(x==1){
            u=0;
            laoda(x,y+1,h+1);
        }else{
            laoda(x-1,y,h+1);
        }
    }

}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+x+1,cmp);
    laoda(1,1,1);
    return 0;
}
