#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
            else if(a[i]==a[i+1]){
                ans++;
                i++;
            }
        }
        cout<<ans;
        return 0;
    }else if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
            else if((a[i]==a[i+1]+1&&a[i]%2==1)||(a[i]+1==a[i+1]&&a[i]%2==0)){
                ans++;
                i++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
