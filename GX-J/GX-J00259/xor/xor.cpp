#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],ans;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                ans++;
                i++;
            }
        }
    }else{
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]){
                ans++;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
