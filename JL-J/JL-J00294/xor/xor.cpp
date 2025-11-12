#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
