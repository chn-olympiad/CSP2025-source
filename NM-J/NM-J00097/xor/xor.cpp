#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[50005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
        }
        if(a[i]!||a[i+1]==k || a[i]!||a[i+1]||a[i+2]==k){
            ans++;
        }

    }
    cout<<ans;

}
