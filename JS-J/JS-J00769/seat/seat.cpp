#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y;
    int cj[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>cj[i];
    }
    int p=cj[1];
    int ans;
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(cj[i]<cj[i+1]){
                swap(cj[i],cj[i+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(cj[i]==p){
            ans=i;
            break;
        }
    }
    if(ans%n==0){
        y=ans/n;
        if(y%2==0){
            x=1;
        }
        else{
            x=n;
        }
        cout<<y<<' '<<x;
        return 0;
    }
    else{
        y=ans/n+1;
        if(y%2==0){
            x=n-ans%n+1;
        }
        else {
            x=ans%n;
        }
        cout<<y<<' '<<x;
    }
    return 0;
}
