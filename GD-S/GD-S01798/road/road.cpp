#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct node{
    int u,v;
    long long w;
    bool operator<(node o){
        return w<o.w;
    }
} edge[2000005],tmp[2000005],ei[1000005],ed[15][10005];
int n,m,k;
long long c[15];

int F[10105];
int find_(int a){
    if(!F[a]) return a;
    return F[a]=find_(F[a]);
}
void link(int a,int b) {
    F[find_(a)] = b;
}

void merge(int cnt,int i){
    int li=1,ri=1,ct=0;
    while(li<=cnt && ri<=n){
        if(edge[li]<ed[i][ri]) {
            tmp[++ct]=edge[li];
            li++;
        }
        else{
            tmp[++ct]=ed[i][ri];
            ri++;
        }
    }
    while(li<=cnt){
        tmp[++ct]=edge[li];
        li++;
    }
    while(ri<=n){
        tmp[++ct]=ed[i][ri];
        ri++;
    }
    memcpy(edge+1,tmp+1,sizeof(node)*(cnt+n));
}

long long spinfe(int p){
    memcpy(edge+1,ei+1,sizeof(node)*m);
    memset(F,0,sizeof F);
    vector<pair<int,int>> tree[10105] = {};
    int cnt=m,ck=n;
    long long ans=0;
    for(int i=1;i<=k;i++){
        if(p&(1<<(i-1))){
            ans+=c[i];
            ck++;
            merge(cnt,i);
            cnt+=n;
        }
    }
    int cb=0;
    for(int i=1;i<=cnt && cb<ck-1;i++){
        int u=edge[i].u,v=edge[i].v;
        long long w=edge[i].w;
        if(find_(u)!=find_(v)){
            ans+=w;
            cb++;
            link(u,v);
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
        }
    }
    for(int i=1;i<=k;i++){
        if(tree[n+i].size()==1){
            ans-=c[i];
            ans-=tree[n+i][0].second;
        }
    }
    return ans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>ei[i].u>>ei[i].v>>ei[i].w;
    sort(ei+1,ei+m+1);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ed[i][j].w;
            ed[i][j].u=n+i;
            ed[i][j].v=j;
        }
        sort(ed[i]+1,ed[i]+n+1);
    }
    long long minn=1e18;
    int jump=0;
    for(int i=0;i<(1<<k);i++){
        if(jump & i) continue;
        long long now=spinfe(i);
        if(now<minn) minn=now;
        else jump |= i;
    }
    cout<<minn;
    return 0;
}

