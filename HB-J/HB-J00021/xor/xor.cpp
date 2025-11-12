#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int m[N];
int n,k,ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    if(n<=2&&k==0){
        ans=n;
    }
    else{

    }

    cout<<ans;
    return 0;
}