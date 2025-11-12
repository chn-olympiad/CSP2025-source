#include<bits/stdc++.h>
using namespace std;
int n,k,a[1200000],ans;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1) ans++;
        }
    }
    else if(k==0){
        int o=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0){
                o=0;
                ans++;
            }
            else if(a[i]==1){
                if(o==1){
                    ans++;
                    o=0;
                }
                else o=1;
            }
        }
    }
    else ans==1;
    cout<<ans;
    return 0;
}

