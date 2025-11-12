#include<bits/stdc++.h>
using namespace std;
int n,m,a,s=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=2;i<=n*m;i++){
        int x;
        cin>>x;
        if(x>a){
            s++;
        }
    }
    int x,y;
    x=s/n;
    y=s%n;
    if(x%2==0){
        if(y==0){
            cout<<x<<" "<<1;
        }
        else{
            cout<<x+1<<" "<<y;
        }
    }
    else{
        if(y==0){
            cout<<x<<" "<<n;
        }
        else{
            cout<<x+1<<" "<<n-y+1;
        }
    }
    return 0;
}
