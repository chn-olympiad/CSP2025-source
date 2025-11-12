#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int check(int l,int r){
    int x=a[l];
    for(int i=l+1;i<=r;i++){
        x=(x^a[i]);
    }
    return x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
        }
    }
    for(int i=1;i<=n;i++){
        int l=i;
        for(int j=i+1;j<=n;j++){
            int r=j;
            if(check(l,r)==k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
