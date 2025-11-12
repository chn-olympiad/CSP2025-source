#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    bool flg=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k>1) return 0;
    if(k==1){
        for(int i=1;i<=n;i++) if(a[i]==1) ans++;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==0) ans++;
            else if(a[i]==1){
                if(a[i+1]==1&&i+1<=n){
                    ans++;
                    i++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
