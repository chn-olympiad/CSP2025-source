#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
using namespace std;
const int N=5e5+5;
ll n,k,ans;
ll a[N],s[N];
map<ll,vector<ll> > mp;
vector<pair<ll,ll> > v;
priority_queue<ll> q;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]^a[i];
    }
    mp[0].push_back(0);
    ll idx=0;
    for(ll i=1;i<=n;i++){
        idx=s[i]^k;
        if(mp[idx].size()!=0){
            v.push_back({mp[idx][0]+1,i});
        }
        if(mp[s[i]].size()==0){
            mp[s[i]].push_back(i);
        }
        else{
            mp[s[i]][0]=max(i,mp[s[i]][0]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(q.empty()){
            ans++;
            q.push(v[i].sec);
            continue;
        }
        if(v[i].fir>q.top()){
            ans++;
            q.push(v[i].sec);
        }
        if(v[i].fir<q.top()){
            if(v[i].sec<q.top()){
                q.pop();
                q.push(v[i].sec);
            }
        }
    }
    printf("%lld",ans);
}
