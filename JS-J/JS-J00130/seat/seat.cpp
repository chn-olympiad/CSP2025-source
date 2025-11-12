#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[205];
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,cmp);
    int Rid=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            Rid=i;
            break;
        }
    }
    int x;
    int y=(Rid-1)/n+1;
    if(y%2==1){
        x=Rid%n;
        if(x==0){
            x+=n;
        }
    }
    else{
        x=Rid%n;
        if(x==0){
            x+=n;
        }
        x=n-x+1;
    }

    cout<<y<<" "<<x;
    return 0;
}
