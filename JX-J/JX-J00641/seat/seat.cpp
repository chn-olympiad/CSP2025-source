#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[102][102],s[10002],ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++) cin>>s[i];
    int p=s[1];
    sort(s+1,s+t+1);
    for(int i=1;i<=t;i++){
        if(p==s[i]){
            ans=i;
            break;
        }
    }
    ans=t-ans+1;
    if(ans%n==0){
        if((ans/n)%2==1) cout<<ans/n<<" "<<n<<endl;
        else cout<<ans/n<<" "<<1<<endl;
    }
    else{
        if((ans/n)%2==0) cout<<ans/n+1<<" "<<ans%n<<endl;
        else cout<<ans/n+1<<" "<<n-(ans%n)+1<<endl;
    }
    return 0;
}