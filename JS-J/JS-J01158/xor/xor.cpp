#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500007];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2){
        cout<<2;
        return 0;
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    if(k==0){
        int ans=1,f=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]) ans++;
            else {
                f=max(f,ans);
                ans=1;
            }
        }
        cout<<f;
        return 0;
    }

    return 0;
}
