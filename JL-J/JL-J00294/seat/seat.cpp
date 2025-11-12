#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0,ans=1,ansx=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int x;
        cin>>x;
        if(i==1){
            cnt=x;
        }else if(x>cnt){
            ans++;
            if(ans==n+1){
                ansx++;
                ans-=n;
            }
        }
    }
    cout<<ansx<<" ";
    if(ansx%2==0){
        cout<<n-ans+1;
    }else{
        cout<<ans;
    }
    return 0;
}
