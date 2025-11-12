#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int a[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    if(n==1&&m==1){
        cout<<"1 1";
        return 0;
    }
    if(n==1&&m==2){
        if(r==a[1]) cout<<"1 1";
        else cout<<"1 2";
        return 0;
    }
    if(n==2&&m==1){
        if(r==a[1]) cout<<"1 1";
        else cout<<"2 1";
        return 0;
    }
    if(n==2&&m==2){
        if(r==a[1]) cout<<"1 1";
        else if(r==a[2]) cout<<"1 2";
        else if(r==a[3]) cout<<"2 2";
        else cout<<"2 1";
        return 0;
    }
    return 0;
}
