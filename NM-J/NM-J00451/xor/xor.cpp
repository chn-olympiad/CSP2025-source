#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0){
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(x==0) ans++;
        }
    }
    cout<<ans;
}
