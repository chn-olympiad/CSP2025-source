#include <bits/stdc++.h>
using namespace std;
#define lint long long
lint n,num[5010],ans=0;
map<string,bool> mp;
const long long md=998244353;
void dfs(int nw,lint tot,lint mx,int t,string sans){
    if(!mp[sans]&&t>=3&&tot>2*mx){
        ans++;
        ans%=md;
        mp[sans]=true;
    }
    if(nw>n) return;
    dfs(nw+1,tot,mx,t,sans);
    dfs(nw+1,tot+num[nw],max(mx,num[nw]),t+1,sans+(char)nw);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    dfs(1,0,0,0,"");
    cout<<ans;
    return 0;
}
