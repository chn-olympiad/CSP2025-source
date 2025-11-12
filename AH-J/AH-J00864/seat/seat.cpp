#include<bits/stdc++.h>
using namespace std;

int s,n,m,x,t;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<n*m;i++){
        cin>>t;
        s+=(t>x);
    }
    int lie=s/n+1,hang;
    if(lie%2){
        hang=s%n+1;
    }
    else{
        hang=n-s%n;
    }
    cout<<lie<<"  "<<hang;
    return 0;
}
