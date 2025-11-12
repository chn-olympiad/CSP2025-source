#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ans+=pow(n,i);
    }
    cout<<ans%998244353;
    return 0;
}