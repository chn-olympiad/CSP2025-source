#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200010];
int b[200010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
            }
            if(a[i]==1&&a[i-1]==1&&b[i]==0&&b[i-1]==0){
                b[i]=1;
                b[i-1]=1;
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
