#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],S,g,pos,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    S=n*m;
    for(int i=1;i<=S;i++){
        cin>>a[i];
    }
    g=a[1];
    sort(a+1,a+1+S,greater<int>());
    for(int i=1;i<=S;i++){
        if(a[i]==g){
            pos=i;
            break;
        }
    }
    x=1,y=0;
    while(pos>n){
        pos-=n;
        x++;
    }
    if(x&1){
        y=pos;
    }else{
        y=n+1-pos;
    }
    cout<<x<<' '<<y;
    return 0;
}
