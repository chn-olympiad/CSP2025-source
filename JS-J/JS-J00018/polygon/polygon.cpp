#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int fuck(int x,int y){
    int w=0,z=a[x];
    for(int i=x;i<=y;i++){
        z=max(z,a[i]);
        w+=a[i];
    }
    if(w>2*z){
        return 1;
    }else{
        return 0;
    }
}
int cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    if(n==3){
        int x=0,y=a[1];
        for(int i=1;i<=3;i++){
            y=max(y,a[i]);
            x+=a[i];
        }
        if(x>2*y){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          cnt+=fuck(i,j);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
