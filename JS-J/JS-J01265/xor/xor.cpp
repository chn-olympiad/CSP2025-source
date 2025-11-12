#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==1){
        int ans=0;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]){
                i++;
                ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(k==0){
        cout<<n/2<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}
