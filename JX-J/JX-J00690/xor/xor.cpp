#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j=1,s=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int o=i;o<=j;o++){
                s=s^a[i];
            }
            if(s==k){
                ans++;
                if(j+1<=n){
                    i=j+1;
                }
                else{
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
