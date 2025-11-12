#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=20,mod=998244353;
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);++i)
int n,m;
string s;
int a[N+5];
int f[1<<N][N+5];
void add(int&x,const int y){
    x+=y;
    while(x>=mod)x-=mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    m=n-m;
    FOR(i,0,n-1)cin>>a[i];
    f[0][0]=1;
    FOR(i,0,(1<<n)-1)FOR(j,0,m)if(f[i][j]){
        int popc(0);
        FOR(k,0,n-1)if((i&(1<<k))!=0)++popc;
        FOR(k,0,n-1)if((i&(1<<k))==0)add(f[i|(1<<k)][j+(s[popc]=='0'||a[k]<=j)],f[i][j]);
    }
    int ans(0);
    FOR(i,0,m)add(ans,f[(1<<n)-1][i]);
    cout<<ans;
    return 0;
}
