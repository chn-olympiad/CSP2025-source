#include<bits/stdc++.h>
using namespace std;
int n,k,x,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==k)
            ans++;
    }
    cout<<ans;
    return 0;
}
