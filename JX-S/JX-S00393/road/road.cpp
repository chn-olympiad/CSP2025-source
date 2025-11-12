#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define db long double
#define F(i,k,n) for (int i=(k);i<=(n);i++)
#define R(i,k,n) for (int i=k;i>=n;i--)
#define ins insert
#define mpr make_pair
#define pu push_back
#define mes(a,b) memset(a,b,sizeof a);
//2326968
const int N=1e4+20;
const int M=13;
const int inf=1e18;
struct edge{
    int from,to,w;
};
vector<edge>vec[M],re,e,q;
int n,m,k,a,b,c;
int d[M];
int cc[M];
int fa[N];
int ans=inf;
inline bool cmp(edge a,edge b){
    return a.w<b.w;
}
inline int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    F(i,1,m){
        cin>>a>>b>>c;
        re.pu({a,b,c});
    }
    F(i,1,n+k) fa[i]=i;
    sort(re.begin(),re.end(),cmp);
    F(i,0,(int)re.size()-1){
        if (find(re[i].from)!=find(re[i].to)){
            fa[find(re[i].from)]=find(re[i].to);
            e.pu(re[i]);
        }
    }
    F(i,0,k-1){
        cin>>cc[i];
        F(j,1,n){
            cin>>a;
            vec[i].pu({i+n+1,j,a});
        }
        sort(vec[i].begin(),vec[i].end(),cmp);
    }
    F(i,0,(1<<k)-1){
        int sum=0;
        F(j,0,k-1){
            if ((i>>j)&1) sum+=cc[j];
            d[j]=0;
        }//127158858045
        F(j,1,n+k) fa[j]=j;
        F(j,0,(int)e.size()-1){
            F(p,0,k-1) q.clear();
            F(p,0,k-1){
                if (!((i>>p)&1)) continue;
                while (d[p]<=n-1 && vec[p][d[p]].w<=e[j].w){
                    if (find(vec[p][d[p]].from)!=find(vec[p][d[p]].to))q.pu(vec[p][d[p]]);
                    d[p]++;
                }
            }
            sort(q.begin(),q.end(),cmp);
            F(o,0,(int)q.size()-1){
                if (find(q[o].from)!=find(q[o].to)){
                    fa[find(q[o].from)]=find(q[o].to);
                    sum+=q[o].w;
                }
            }
            if (find(e[j].from)!=find(e[j].to)){
                fa[find(e[j].from)]=find(e[j].to);
                sum+=e[j].w;
            }
            if (sum>=ans) break;
            q.pu(e[j]);
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/