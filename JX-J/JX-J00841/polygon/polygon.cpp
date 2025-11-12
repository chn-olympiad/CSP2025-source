#include <bits/stdc++.h>
using namespace std;
int n,k,a[5005],maxx,sum;
long long ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxx=max(maxx,a[i]);
    }
    if(maxx==1){
        ans=1;
        for(int i=1;i<=n;i++){
            ans*=2;
            ans=ans%998244253;
        }
        ans=ans-n-1-(n*(n-1)/2);
    }
    else if(n==3){
        if(sum>2*maxx){
            ans=1;
        }
        else{
            ans=0;
        }
    }
    cout<<ans;
    return 0;
}
