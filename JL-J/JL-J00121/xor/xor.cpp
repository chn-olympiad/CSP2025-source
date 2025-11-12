#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k,ans=0;
    cin>>n>>k;
    long long a[500010]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){}
        ans++;
    }
    cout<<ans;
    return 0;
}
