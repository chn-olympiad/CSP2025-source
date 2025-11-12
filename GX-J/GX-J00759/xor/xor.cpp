#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],k;
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==a[i-1]&&a[i-1]==0){
                ans++;
            }
        }
        cout<<ans;
    }
    else{
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            ans++;
        }
    }
    cout<<n-ans;
    }
    return 0;
}
