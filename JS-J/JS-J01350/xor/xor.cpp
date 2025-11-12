#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
int vis[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
        }
        cout<<ans;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sss=a[i];
            for(int b=i;b<=j;b++){
                sss^=a[b];
                if(sss==k){
                    i=j;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
