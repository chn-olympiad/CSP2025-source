#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a=0,c,p,q;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        if(i==1){
            cin>>c;
        }else{
            int b;
            cin>>b;
            if(b>c)a++;
        }
    }
    p=a/n+1;
    if(p%2==0){
        q=n-a%n;
    }else{
        q=(a%n+1);
    }
    cout<<p<<' '<<q;
}
