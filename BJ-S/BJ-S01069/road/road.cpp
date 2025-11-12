#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,f[N<<1];
int c[15];
int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
struct ed{
    int u,v,c;
}e[M];
ed g[15][N];
bool cmp(ed x,ed y){
    return x.c<y.c;
}
vector<ed>tree;
int bg[15];
void print(int mask){
    for(int i=1;i<=k;i++){
        cout<<((mask>>(i-1))&1);
    }
    cout<<endl;
}
ll solve(int mask){
   // print(mask);
    vector<int>add;ll tot=0;
    for(int i=1;i<=k;i++){
        if((mask>>(i-1))&1){
            add.push_back(i);
            tot+=c[i];
        }
    }
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=0;i<=k;i++)bg[i]=1;
    bg[0]=0;int cnt=0;
    for(int i=1;;i++){
        int id=0;ed mn={0,0,1000000000};
        if(bg[0]<tree.size())mn=tree[bg[0]];
        for(auto j:add){
            if(bg[j]>n)continue;
            if(g[j][bg[j]].c<=mn.c){
                mn=g[j][bg[j]];
                id=j;
            }
        }
        bg[id]++;
        //cout<<"ADD "<<mn.u<<" "<<mn.v<<" "<<mn.c<<endl;
        if(find(mn.u)==find(mn.v))continue;
        tot+=mn.c;
        cnt++;
        if(cnt==n+add.size()-1)break;
        f[find(mn.u)]=find(mn.v);
    }
    //cout<<tot<<endl;
    return tot;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].c;
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,c=e[i].c;
        if(find(u)==find(v))continue;
        tree.push_back(e[i]);
        f[find(u)]=find(v);
        if(tree.size()==n-1)break;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            g[i][j].u=n+i;
            g[i][j].v=j;
            cin>>g[i][j].c;
        }
        sort(g[i]+1,g[i]+n+1,cmp);
    }
    ll ans=1e18;
    for(int i=0;i<(1<<k);i++){
        ans=min(ans,solve(i));
    }
    cout<<ans<<endl;
    return 0;
}