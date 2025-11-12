#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10];
int main(){
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1) cout<<1;
    else if(a[1]==0&&a[2]==0) cout<<2;
    else if(a[1]^a[2]==0) cout<<1;
    else cout<<2;

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    return 0;
}
