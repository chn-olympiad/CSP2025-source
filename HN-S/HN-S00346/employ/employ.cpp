#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,m,c[N],a[N],z[N];
bitset<N> vis,pan;
const int mod=998244353;
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
string s;
int p[N],ans;
void dfs(int cnt)
{
    if(cnt==n+1){
        int res=0,cnt=0;
        for(int i=1;i<=n;++i){
            if(res>=c[p[i]]){
                ++res;
                continue;
            }
            if(vis.test(i)) ++cnt;
            else{
                ++res;
            } 
        }
        if(cnt>=m) ++ans;
        return ;
    }
    for(int i=1;i<=n;++i){
        if(!pan.test(i)){
            pan.set(i);
            p[cnt]=i;
            dfs(cnt+1);
            pan.reset(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;++i){
        if(s[i]-'0') vis.set(i+1);
    }
    for(int i=1;i<=n;++i) cin>>c[i];
    dfs(1);
    cout<<ans<<"\n";
    return 0;
}