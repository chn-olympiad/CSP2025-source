#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,p,x,y;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",strout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            p=i;
            break;
        }
    }
    x=p/n;
    y=p%n;
    if(y){
        x++;
        if(x%2==0){
            y=n-y+1;
        }
    }
    else{
        if(x%2==1){
            y=n;
        }
        else{
            y=1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
