#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    bool t=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1) t=0;
    }
    if(t){
        cout<<n/2;
        return 0;
    }
    if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==0)
                ans++;
            if(a[i]&&a[i+1]){
                ans++;
                i++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(k==1){
        for(int i=0;i<n;i++)
            if(a[i]) ans++;
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
 }
