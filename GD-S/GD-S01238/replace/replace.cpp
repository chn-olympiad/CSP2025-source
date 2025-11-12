#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn = 2e5+7;
ll n,q;

string s[maxn][2],r[maxn][2];
static inline bool issame(int idx,const string&a,const string&b){
    if(idx+b.size()>a.size()){
        return false;
    }
    for(int i=0;i<b.size();i++){
        if(a[i+idx]!=b[i])return false;
    }
    return true;
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(ll i=1;i<=q;i++){
        cin>>r[i][0]>>r[i][1];
        ll ans=0;
        for(ll j=1;j<=n;j++){
            for(ll k=0;k<r[i][0].size();k++){
                if(issame(k,r[i][0],s[j][0])){
                    auto tmp = r[i][0];
                    for(int l=0;l<s[j][0].size();l++){
                        tmp[l+k]=s[j][1][l];
                    }
                    if(tmp==r[i][1])ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}