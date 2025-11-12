#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fo(i,v) for(auto i:v)
ll n,a[5005],ans;
const ll mod=998'244'353;
void dfs(ll k,ll mx,ll cnt,ll s,bool flag) { //k->i mx->max cnt->sum_of_all_chosen s->num_of_all_chosen
    bool fl=flag;
    if(k>n) {
        if(s>=3 && cnt>2*mx && fl) {
            ans++;
            ans%=mod;
        }
        return ;
    }
    if(k>=1 && k<=n && s>=3 && cnt>2*mx && fl) {
        ans++;
        ans%=mod;
        fl=0;
    }
    dfs(k+1,mx,cnt,s,fl);
    dfs(k+1,max(mx,a[k]),cnt+a[k],s+1,1);
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    f(i,1,n) cin>>a[i];
    dfs(1,0,0,0,0);
    cout<<ans;
    return 0;
}
/* Expected Score: [24,40] */
