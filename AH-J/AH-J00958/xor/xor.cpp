#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,k;
int cnt;
int ans;
map<int,bool> mp;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==k) ans++,cnt=0,mp.clear();
        else{
            cnt=cnt xor a;
            mp[cnt]=true;
            if(mp[k xor cnt]) ans++,cnt=0,mp.clear();
            else if(cnt==k) ans++,cnt=0,mp.clear();
        }
    }cout<<ans;
    return 0;
}
