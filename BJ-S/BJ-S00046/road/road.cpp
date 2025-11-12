#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;
int n,m,k;
struct tu{
    int u,v,w;
};
int a[20][MAXN];
int s[20];
int ans;
vector <tu> t[MAXN];
int ww[1000010],wtop;
void add(int u,int v,int w){
    t[u].push_back({u,v,w});
    t[v].push_back({v,u,w});
}
bool cmp(int x,int y){
    return x<y;
}
int ji[MAXN];
void build_ji(){
    for(int i=1;i<=n;i++){
        ji[i]=i;
    }
}
int find_ji(int x){
    if(ji[x]==x)return x;
    else return find_ji(ji[x]);
}
void merge_ji(int x,int y){
    x=find_ji(x);
    y=find_ji(y);
    if(x==y)return;
    if(x>y)swap(x,y);
    ji[y]=x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        ww[++wtop]=w;
    }
    sort(ww+1,ww+m+1,cmp);
    for(int i=1;i<=n-1;i++){
        ans+=ww[i];
    }
    for(int i=1;i<=k;i++){
        cin>>s[i];
        int anss=s[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            anss+=a[i][j];
        }
        ans=min(ans,anss);
    }
    cout<<ans;
    return 0;
}
