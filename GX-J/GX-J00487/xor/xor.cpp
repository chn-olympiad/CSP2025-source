#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    int a[n+20];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
