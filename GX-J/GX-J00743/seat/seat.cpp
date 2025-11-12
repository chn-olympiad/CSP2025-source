#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a,ans=1;
    cin>>a;
    for(int i=0;i<m*n-1;i++){
        int b;
        cin>>b;
        if(b>a){
            ans++;
        }
    }
    //cout<<ans<<" "<<ans/n<<" "<<ans%n;
    if(ans%n==0){
            cout<<ans/n<<" ";
        if((ans/n)%2==0){
            cout<<1;
        }else{
            cout<<n;
        }
    }else{
        cout<<ans/n+1<<" ";
        if((ans/n)%2==0){
            cout<<ans%n;
        }else{
            cout<<n-(ans%n)+1;
        }
    }
    return 0;
}
