#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,b,c[105],sum=1,d,e,f,g;
    cin>>n>>m;
    cin>>b;
    a=n*m;
    for(int i=1;i<=a-1;i++){
        cin>>c[i];
        if(b<c[i]){
            sum++;
        }
    }
    d=sum/n;
    if(sum%n!=0){
        d=d+1;
    }
    if(d%2!=0){
        if(sum%n==0){
            e=n;
        }
        else{
            e=sum%n;
        }
    }
    else{
        f=sum%n;
        g=n+1;
        e=g-f;
    }
    cout<<d<<" "<<e;
    return 0;
}
