#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>t;
    for(int i=1;i<n*m;i++){
        cin>>x;
        if(x>t){
            s++;
        }
    }
    if((s+1)%n==0){
        if((s+1)/n%2==0){
            cout<<(s+1)/n<<' '<<1;
        }else{
            cout<<(s+1)/n<<' '<<n;
        }

    }else{
        if(((s+1)/n+1)%2==0){
            cout<<(s+1)/n+1<<' '<<n-(s+1)%n+1;
        }else{
            cout<<(s+1)/n+1<<' '<<(s+1)%n;
        }
    }
    return 0;
}
