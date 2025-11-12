#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+15,N=1e4+15;
int n,m,k,cnt,sum,ans,val,tmp,x;
int tot;
int f[M];
struct node{
    int x,y,val,col;//col:种类
}a[M],b[M];
int c[20];
int nxt[M],col[20];
int deg[20];
priority_queue<int,vector<int>,greater<int> >q;
bool cmp(node x,node y){
    return x.val<y.val;
}
inline int get(int x){return (f[x]^x)?f[x]=get(f[x]):x;}
inline int merge(int x,int y){
    x=get(x),y=get(y);
    if(x==y)return 0;
    f[x]=y;
    return 1;
}
// void sol(){
//     for(int i=1;i<=k;i++){
//         cin>>c[i];
//         for(int j=1;j<=n;j++){
//             cin>>d[i][j];
//             b[++cnt]=(node){i+n,j,d[i][j],i};
//         }
//         sort(b+1,b+cnt+1,cmp);
//         iota(f,f+n+k,0);
//         memset(deg,0,sizeof(deg));
//         tot=0;val=0;
//         for(int j=1;j<=cnt;j++){
//             if(merge(b[j].x,b[j].y))a[++tot]=a[j],val+=b[j].val,deg[b[j].col]++;
//         }
//         for(int j=1;j<=k;j++)if(deg[j])val+=c[j];
//         if(val<ans){
//             for(int j=1;j<=tot;j++)b[j]=a[j];
//             cnt=tot;
//             ans=val;
//         }
//     }
//     cout<<ans<<"\n"; 
// }
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    iota(f,f+n+1,0);
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].val;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(merge(a[i].x,a[i].y))b[++cnt]=a[i],ans+=a[i].val;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>x;
            b[++cnt]=(node){i+n,j,x,i};
        }
    }
    sort(b+1,b+cnt+1,cmp);
    for(int i=cnt;i;i--){
        nxt[i]=col[b[i].col];
        col[b[i].col]=i;
    }
    for(int S=0;S<(1<<k);S++){
        while(!q.empty())q.pop();
        q.push(col[0]);
        tmp=sum=val=0;
        for(int j=1;j<=k;j++){
            if(S&(1<<(j-1))){
                q.push(col[j]);
                tmp++;
                val+=c[j];
            }
        }
        iota(f,f+n+k+1,0);
        while(!q.empty()){
            int x=q.top();q.pop();
            if(merge(b[x].x,b[x].y))val+=b[x].val,sum++;
            if(sum+1==n+tmp||val>=ans)break;
            if(nxt[x])q.push(nxt[x]);
        }
        if(sum+1==n+tmp)ans=min(ans,val);
    }
    cout<<ans;
    return 0;
}