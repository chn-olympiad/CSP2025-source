#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,ans;
bool f=true;
unordered_map<int,int> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
    x=1;
    for(int i=1;i<=n;i++){
        if(f&&a[i]==k){
            ans++,f=false,mp[a[i]]=i;
            continue;
        }
        int t=k^a[i];
        if(mp[t]>=x) f=false,x=i,ans++;
        mp[a[i]]=i;
    }
    cout<<ans;
    return 0;
}
