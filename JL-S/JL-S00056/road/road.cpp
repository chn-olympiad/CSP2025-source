#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define mkp make_pair
#define fi first
#define se second
const int N=10024,M=1200024;
int n,m,k,tp;
struct edge{
    int x,y,z;
}E[M];
int fa[N],id[M],idn[15][N],cnt,p[N],c[N],ans,f[N];
bool cmp(int x,int y){
    return E[x].z<E[y].z;
}
bool cmp2(edge x,edge y){
    return x.z<y.z;
}
inline int findfa(int cur){
    if(cur==fa[cur]) return cur;
    return fa[cur]=findfa(fa[cur]);
}
inline bool merge(int x,int y){
    int X=findfa(x),Y=findfa(y);
    if(X==Y) return 0;
    fa[X]=Y;
    return 1;
}
void dfs(int cur,int cnt,int lst,int tot){
    if(cur==k+1){
        if(cnt==0) return;
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        int num=0,cc=f[lst];
        for(int i=1;i<=(n-1)+(cnt-1);i++){
            int tt=idn[cnt-1][i];
            //cout<<tt<<" "<<E[tt].z<<"waiting\n";
            while(cc<f[lst]+n&&E[cc].z<E[tt].z){
                //cout<<"now cc:"<<cc<<" "<<E[cc].x<<" "<<E[cc].y<<" "<<E[cc].z<<"\n";
                if(merge(E[cc].x,E[cc].y)){
                    tot+=E[cc].z;
                    idn[cnt][++num]=cc;
                    //cout<<num<<" "<<tot<<"wow!\n";
                    if(num==n+cnt-1) break;
                }
                cc++;
            }
            if(merge(E[tt].x,E[tt].y)){
                tot+=E[tt].z;
                idn[cnt][++num]=tt;
                if(num==n+cnt-1) break;
            }
        }
        //cout<<tot<<"!!!\n";
        ans=min(ans,tot);
        return;
    }
    dfs(cur+1,cnt,lst,tot);
    dfs(cur+1,cnt+1,cur+n,tot+c[cur+n]);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>E[i].x>>E[i].y>>E[i].z;
        id[i]=i;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    stable_sort(id+1,id+1+m,cmp);
    cnt=0;
    for(int i=1;i<=m;i++){
        if(merge(E[id[i]].x,E[id[i]].y)){
            ans+=E[id[i]].z;
            cnt++;
            idn[0][cnt]=id[i];
            if(cnt==n-1) break;
        }
    }
    tp=m;
    for(int i=1;i<=k;i++){
        cin>>c[n+i];
        f[n+i]=tp+1;
        for(int j=1;j<=n;j++){
            E[++tp].x=n+i;
            E[tp].y=j;
            cin>>E[tp].z;
        }
        sort(E+f[n+i],E+tp+1,cmp2);
    }
    dfs(1,0,0,0);
    cout<<ans<<"\n";
}