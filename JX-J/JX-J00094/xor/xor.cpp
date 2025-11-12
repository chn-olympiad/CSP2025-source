#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    ll mp[500010] = {};
    ll maxmp = 0;
    ll minmp = 0;
    for(int i = 1;i<=n;i++){
        cin>>mp[i];
        if(i == 1){
            maxmp = mp[1];
            minmp = mp[1];
        }
        maxmp = max(maxmp,mp[i]);
        minmp = min(minmp,mp[i]);
    }
    if(maxmp == minmp){
        if(k!=maxmp && k != 0){
            cout<<0;
        }else{
            if(k == 0){
                cout<<n/2;
            }else{
                cout<<n;
            }
        }
        return 0;
    }
    int cnt = 0;
    int lastid = 0;
    for(int i = 1;i<=n;i++){
        ll nowex = 0;
        for(int j = i;j>lastid;j--){
            nowex = nowex^mp[j];
            if(nowex == k){
                //cout<<j<<" "<<i<<"\n";
                cnt++;
                lastid = i;
                break;
            }
        }
    }
    cout<<cnt;
}
