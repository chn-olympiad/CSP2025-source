#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define repr(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=(int)(5010),mod=998244353;

ll a[maxn];

bool ans[maxn];

ll fans=0,n;

void dfs(ll dep){
    if(dep>n){
        ll sum=0;
        ll mx=0;
        rep(i,1,n){
            if(ans[i]==true){
                sum+=a[i];
                mx=max(mx,a[i]);
            }
        }
        if(sum>mx*2){
            fans++;
        }
        return;
    }
    //cerr<<">_<"<<endl;

    ans[dep]=false;
    dfs(dep+1);
    ans[dep]=true;
    dfs(dep+1);

    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    ll mx=0;

    rep(i,1,n)cin>>a[i],mx=max(mx,a[i]);

    if(n<=25){
        dfs(1);

        cout<<fans%mod<<endl;
    }
    else{
        if(mx==1){
            fans=1;
            rep(i,1,n){
                rep(j,n-i+1,n){
                    fans*=j;
                    fans%=mod;
                }
                rep(j,1,i){
                    fans/=j;
                }
                //cout<<fans<<" ";
            }
            cout<<fans%mod<<endl;
        }
    }

    return 0;
}
