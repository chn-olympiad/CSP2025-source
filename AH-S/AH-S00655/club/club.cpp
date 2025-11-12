#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+5;
int n,op[N],tot;
ll a[N][5];
ll res[N],cnt[5];

void solve(){
    ll ans=0;
    tot=0;
    up(j,1,3) cnt[j]=0;
    cin>>n;
    up(i,1,n) up(j,1,3) cin>>a[i][j];
    up(i,1,n){
        op[i]=1;
        up(j,2,3) if (a[i][j]>a[i][op[i]]) op[i]=j;
        cnt[op[i]]++;
        ans+=a[i][op[i]];
    }
    int id=1;
    up(i,2,3) if (cnt[i]>cnt[id]) id=i;
    if (cnt[id]<=n/2){
        cout<<ans<<'\n';
        return;
    }
    up(i,1,n){
        if (op[i]==id){
            ll maxx=0;
            up(j,1,3){
                if (j==id) continue;
                maxx=max(maxx,a[i][j]);
            }
            res[++tot]=a[i][id]-maxx;
        }
    }
    sort(res+1,res+tot+1);
    up(i,1,cnt[id]-(n/2)) ans-=res[i];
    cout<<ans<<'\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while (t--) solve();
    return 0;
}
