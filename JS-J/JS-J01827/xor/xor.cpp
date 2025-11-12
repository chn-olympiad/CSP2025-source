#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,ans=0,p;
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=1;
        }
    }
    if(k==0&&!f){
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int q=a[i] xor a[i+1];
        if(a[i]==k){
            ans++;
            continue;
        }
        if(q==k){
            ans++;
            i++;
            continue;
        }
    }
    cout<<ans;
    return 0;
}
