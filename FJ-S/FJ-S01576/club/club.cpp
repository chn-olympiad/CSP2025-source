#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define R read<int>()
#define fi first
#define se second
using namespace std;
template <typename T> inline T read(){
    T x=0,fl=1; char c=getchar();
    while(c<'0'||c>'9') (c=='-'?fl=-1:1),c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*fl;
}
const int inf=0x3f3f3f3f,N=100005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int T,n,a[N][3],id[N];
ll solvex(int o){
    // cerr<<o<<endl;
    iota(id+1,id+n+1,1);
    int p=(o+1)%3,q=(o+2)%3;
    sort(id+1,id+n+1,[&](int x,int y){
        return max(a[x][p],a[x][q])-a[x][o]>max(a[y][p],a[y][q])-a[y][o]; });
    ll ans=0;
    for(int i=1;i<=n/2;i++) ans+=max(a[id[i]][p],a[id[i]][q]);
    for(int i=n/2+1;i<=n;i++) ans+=a[id[i]][o];
    return ans;
}
void solve(){
    n=R;
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++)
            a[i][j]=R;
    ll ans=0; int cnt[3]={0,0,0};
    for(int i=1;i<=n;i++){
        int p=max_element(a[i],a[i]+3)-a[i];
        ans+=a[i][p],cnt[p]++;
    }
    for(int i=0;i<3;i++){
        if(cnt[i]>n/2){
            printf("%lld\n",solvex(i));
            return;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(T=R;T--;solve());
    return 0;
}