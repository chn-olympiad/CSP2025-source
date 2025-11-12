#include<bits/stdc++.h>
using namespace std;
long long b[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int p=0;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        p=b[1];
    }
    int ans=0;
    sort(b+1,b+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(b[i]==p){
            ans=n*m-i+1;
            break;
        }
    }
    double l=ans*1.00/n;
    if(l==int(ans/n)){
        if(ans/n%2==0){
            cout<<ans/n<<" "<<"1";
        }
        else{
            cout<<ans/n<<" "<<n;
        }
    }
    else{
        if((int(ans/n)+1)%2==0){
            cout<<int(ans/n)+1<<" "<<n-ans%n+1;
        }
        else{
            cout<<int(ans/n)+1<<" "<<ans%n;
        }
    }
    return 0;
}
