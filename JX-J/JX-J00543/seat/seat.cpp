#include<bits/stdc++.h>
using namespace std;
long long n,m,a,pm=1,w=0;
int main(){
    freopen(seat.in,"r",stdin);
    freopen(seat.out,"w",stdout);
    cin>>n>>m;
    for(int i=1,a=0;i<=n*m;i++){
        cin>>a;
        if(i==1){
            w=a;
        }
        if(w<a){
            pm++;
        }
    }
    if(pm%n==0){
        cout<<pm/n<<" ";
        if((pm/n)%2==0){
            cout<<1;
        }else{
            cout<<n;
        }
    }else{
        cout<<pm/n+1<<" ";
        if((pm/n+1)%2==0){
            cout<<n-pm%n+1;
        }else{
            cout<<pm%n;
        }

    }

}
