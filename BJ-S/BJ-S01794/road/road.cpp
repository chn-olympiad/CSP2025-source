#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+25;
const int M=1e6+5;
struct edge{
    int u,v,w;
    bool operator<(const edge l2)const{
        return w<l2.w;
    }
}a[M],b[15][N];
edge ed[M];
int c[15];
int use[N],cur,cur2;
int f[N];
int n,m,k;
ll ans=0;
inline int find(int i){
    if(f[i]==i)return i;
    return f[i]=find(f[i]);
}
inline ll mst(){
    cur2=0;
    ll res=0;
    for(int i=1;i<=n+k;++i)f[i]=i;
    for(int i=1;i<=cur;++i){
        int f1=find(ed[i].u),f2=find(ed[i].v);
        if(f1!=f2){
            f[f1]=f2;
            use[++cur2]=i;
            res+=ed[i].w;
        }
       // cout<<ed[i].u<< " "<<ed[i].v<<" "<<ed[i].w<<"\n";
    }
   // cout<<res<<"?\n";
    return res;
}
edge ls[13][N];
int len[14];
inline void dfs(int i,int pre,ll cst){
    if(i>k)return;
    dfs(i+1,pre,cst);
    cur=len[pre]+n;
    int p1=1,p2=1;
    for(int j=1;j<=cur;++j){
        if(p1<=len[pre]&&(p2>n||ls[pre][p1]<b[i][p2]))ed[j]=ls[pre][p1],++p1;
        else ed[j]=b[i][p2],++p2;
    }
    ans=min(ans,mst()+cst+c[i]);
    len[i]=cur2;
    for(int j=1;j<=cur2;++j){
        ls[i][j]=ed[use[j]];
    }
    dfs(i+1,i,cst+c[i]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   //double t1=clock();
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)ed[i]=a[i];
    for(int i=1;i<=k;++i){
        cin>>c[i];
        for(int j=1;j<=n;++j){
            int w;
            cin>>w;
            b[i][j]={n+i,j,w};
        }
        sort(b[i]+1,b[i]+n+1);
    }
    cur=m;
    ans=mst();
    len[0]=cur2;
    for(int i=1;i<=cur2;++i){
        ls[0][i]=ed[use[i]];
    }
    dfs(1,0,0);
    cout<<ans;
    //double t2=clock();
    //cout<<"\n"<<(t2-t1)/CLOCKS_PER_SEC;
    return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
*/
