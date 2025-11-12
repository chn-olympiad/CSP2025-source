#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    int xo=0;
    int un,ans=0;
    for(int i=1;i<=n;i++){
        cin>>un;
        xo=xo xor un;
        if(xo==k||un==k){
            ans++;
            xo=0;
        }
    }cout<<ans;
    return 0;
}
