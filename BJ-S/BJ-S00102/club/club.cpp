#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5;
ll t,ans=LONG_LONG_MIN;
struct node{
    ll a,b,c;
}cl[maxn+5];
void dfs(ll tmp,ll step,ll peoa,ll peob,ll peoc,ll ntwo){
    if(peoa>ntwo||peob>ntwo||peoc>ntwo)return;
    if(step>(ntwo*2)){
        ans=max(ans,tmp);
        return;
    }
    dfs(tmp+cl[step].a,step+1,peoa+1,peob,peoc,ntwo);
    dfs(tmp+cl[step].b,step+1,peoa,peob+1,peoc,ntwo);
    dfs(tmp+cl[step].c,step+1,peoa,peob,peoc+1,ntwo);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){ 
        ll n;
        cin>>n;
        ll n_two=n/2;
        for(ll i=1;i<=n;i++){
            cin>>cl[i].a>>cl[i].b>>cl[i].c;
        }
        dfs(0,1,0,0,0,n_two);
        cout<<ans<<endl;
        ans=LONG_LONG_MIN;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}