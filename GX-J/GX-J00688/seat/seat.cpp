#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long a[n][m];
    long long s[n*m+10];
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n*m;i++){
        if(s[0]<s[i]) ans++;
    }
    if(ans<=n) cout<<1<<" "<<ans;
    else{
        if(ans%n==0){
            cout<<ans/n<<" ";
            if((ans/n)%2==0){
                cout<<ans%n+1;
            }
            else{
                cout<<ans%n;
            }
        }
        else{
            cout<<ans/n+1<<" ";
            if((ans/n+1)%2==0){
                cout<<ans%n+1;
            }
            else{
                cout<<ans%n;
            }
        }
    }
    return 0;
}
