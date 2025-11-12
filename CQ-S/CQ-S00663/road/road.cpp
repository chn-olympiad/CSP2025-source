#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    inline void read(int&x){
        x=0;char ch=getchar();
        while(ch<'0' || ch>'9') ch=getchar();
        while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    }
    typedef long long ll;
    namespace dsu{
        int f[10025];
        int siz[10025];
        inline void build(int n){for(int i=1;i<=n;i++){f[i]=i;siz[i]=1;}}
        inline int getfa(int u){if(f[u]==u) return u;return f[u]=getfa(f[u]);}
        inline bool merge(int l,int r){
            l=getfa(l);r=getfa(r);if(siz[l]<siz[r]) swap(l,r);
            if(l==r) return 0;
            f[r]=l;siz[l]+=siz[r];return 1;
        }
    }
    struct node{int u,v,val;};
    inline bool cmp(node a,node b){return a.val<b.val;}
    int n,__m,m,k;
    node __b[1000005];
    node b[1000005];
    int c[15];
    node a[15][10005];
    int al[15],ml;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    ll ans;
    void solve(){
        read(n);read(__m);read(k);
        if(n==1){printf("0\n");return;}
        for(int i=1;i<=__m;i++){read(__b[i].u);read(__b[i].v);read(__b[i].val);}
        sort(__b+1,__b+__m+1,cmp);
        dsu::build(n+k);
        for(int i=1;i<=__m;i++) if(dsu::merge(__b[i].u,__b[i].v)) b[++m]=__b[i];
        for(int i=1;i<=k;i++){
            read(c[i]);
            for(int j=1;j<=n;j++){
                read(a[i][j].val);
                a[i][j].u=n+i;a[i][j].v=j;
            }
            sort(a[i]+1,a[i]+n+1,cmp);
        }
        for(int i=1;i<=m;i++) ans+=b[i].val;
        for(int __i=1;__i<(1<<k);__i++){
            dsu::build(n+k);
            ll sum=0;int cnt=0;
            int nl=n;
            for(int i=1;i<=k;i++) if((__i>>(i-1))&1){nl++;sum+=c[i];}
            ml=1;
            q.push({b[1].val,0});
            for(int i=1;i<=k;i++) if((__i>>(i-1))&1){al[i]=1;q.push({a[i][1].val,i});}
            while(!q.empty() && cnt<nl-1){
                int i=q.top().second;q.pop();
                if(i==0){
                    if(dsu::merge(b[ml].u,b[ml].v)){sum+=b[ml].val;cnt++;}
                    ml++;if(ml<=m) q.push({b[ml].val,0});
                }
                else{
                    if(dsu::merge(a[i][al[i]].u,a[i][al[i]].v)){sum+=a[i][al[i]].val;cnt++;}
                    al[i]++;if(al[i]<=n) q.push({a[i][al[i]].val,i});
                }
            }
            ans=min(ans,sum);
            while(!q.empty()) q.pop();
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    mycode::solve();
    return 0;
}