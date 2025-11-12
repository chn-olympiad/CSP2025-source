#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int c[15],n,m,k,a[15],ans=1e18,cnt=0,fa[10005],w[10005];

struct node{
    int num,x,y;
}b[1100005];

bool cmp(node x,node y){
    return x.num<y.num;
}

int getfa(int x){
    if(x==fa[x]) return x;
    fa[x]=getfa(fa[x]);
    return fa[x];
}

int kruskal(){
    int ans2=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    int cur=0;
    for(int i=1;i<=cnt;i++){
        if(getfa(b[i].x)!=getfa(b[i].y)){
            fa[getfa(b[i].x)]=getfa(b[i].y);
            ans2+=b[i].num;
            cur++;
            if(cur==n-1) break;
        }
    }
    return ans2;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    a[0]=1;
    for(int i=1;i<=m;i++){
        int s,t,w;
        cin>>s>>t>>w;
        b[++cnt]={w,s,t};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int tmp;
        for(int j=1;j<=n;j++){
            cin>>w[j];
            if(!w[j]) tmp=j;
        }
        for(int j=1;j<=n;j++){
            if(tmp==j) continue;
            b[++cnt]={w[j],tmp,j};
        }
    }
    sort(b+1,b+cnt+1,cmp);
    cout<<kruskal();
    return 0;
}
