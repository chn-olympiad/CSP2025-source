#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[5005];
int b[5005]={0,0,0,0,2};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    if(n<5){
        ans=b[n];
        cout<<ans;
        return 0;
    }
    ans=b[4];
    for(int i=5;i<=n;i++){
        ans=ans+b[i-1]*2+ceil(i/2)+1;
        b[i]=b[i-1]*2+ceil(i/2)+1;
    }
    cout<<ans;
    return 0;
}
