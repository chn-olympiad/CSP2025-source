#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b;
    cin>>b;
    int cnt=1;
    for(int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        if(a>b){
            cnt++;
        }
    }
    int d;
    if(cnt%n==0){
        d=cnt/n;
    }
    else{
        d=cnt/n+1;
    }
    if(d%2==0){
        cout<<d<<" "<<n-(cnt%n)+1;
    }
    else if(d%2==1){
        if(cnt%n==0){
            cout<<d<<" "<<n;
        }
        else if(cnt%n!=0){
            cout<<d<<" "<<cnt%n;
        }
    }
    return 0;
}
