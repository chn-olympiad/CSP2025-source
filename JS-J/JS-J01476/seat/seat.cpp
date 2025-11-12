#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int w=0,xt=0,yt=0;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    w=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==w){
            w=i;
        }
    }
    if(w<=n){
        xt=w/n;
    }
    else{
        xt=w/n+1;
    }
    if(w%(n*2)<=n){
        yt=w%(n*2);
    }
    else{
        yt=n*2-(w%(n*2))+1;
    }
    cout<<xt<<' '<<yt;
    return 0;
}
