#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005];
bool flag;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)flag=true;
        if(a[i]==1)ans++;
    }
    if(!flag)cout<<n/2;
    else {
        if(k==1)cout<<ans;
        else {
            ans=n-ans;
            for(int i=1;i<=n;i++){
                int l=0;
                while(a[i]==1)l++,i++;
                ans+=l/2;
            }
            cout<<ans;
        }
    }
    return 0;
}
