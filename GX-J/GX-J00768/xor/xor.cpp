#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        for(int i=1;i<=n;i++){
            if(a[i]==1 && a[i+1]==1){
                ans++;
                i++;
            }
            else if(a[i]==0)ans++;
        }
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
    }
    cout<<ans;
    return 0;
}
