#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define f(i,a,b) for(int i=a;i<b;++i)
#define f2(i,a,b) for(int i=a;i<=b;++i)
#define LEN(x) (int)x.size()
const int inf=0x3f3f3f3f;
const int maxn=5e5+5;
map<pii,int> m;
int n,k;
int a[maxn];
int dfs(int pos,int val){
    if(pos==0){
        if(val==k) return 1;
        return 0;
    }
    if(m[make_pair(pos,val)]) return m[make_pair(pos,val)];
    int res=dfs(pos-1,a[pos-1]);
    if(val==k) ++res;
    else res=max(res,dfs(pos-1,val^a[pos-1]));
    return m[make_pair(pos,val)]=res;
}
void solve();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
void solve(){
    cin>>n>>k;
    f2(i,1,n) cin>>a[i];
    cout<<dfs(n,a[n])<<endl;
}