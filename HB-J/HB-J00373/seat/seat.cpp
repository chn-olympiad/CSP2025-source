#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,c,r,a,b;
    cin>>n>>m;
    cin>>a;
    for(long long i=1;i<n*m;i++){
        cin>>b;
        if(a==n*m){
            cout<<"1 1";
        }
        if(a==1){
            cout<<n<<" "<<m;
        }
    }
}
