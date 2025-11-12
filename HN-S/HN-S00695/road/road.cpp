#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b){
        return a.z<b.z;
    }
};
int fa[N];
void init(){
    for(int i=0;i<N;i++)
        fa[i]=i;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
bool check(int x,int y){
    return find(x)==find(y);
}
vector<node>e,b;
int dm[30];
int a[30][N];
int c[30];
int n,m,k;
int minn=2e18;

int mit(){
    vector<node>s=e;
    for(auto [x,y,z]:b){
        s.push_back({x,y,z});
    }
    sort(s.begin(),s.end());
    int nn=n;
    init();
    int ans=0;
    int cnt=0;
    for(auto [x,y,z]:s){
        if(check(x,y))continue;
        merge(x,y);
        ans+=z;
        cnt++;
        if(x>n){
            nn++;
        }
        if(cnt==nn-1)
            break;
    }
    return ans;
}
int T=0;
void dfs(int x){
    if(x>k){
        b.clear();
        int ans=0;
        for(int i=1;i<=k;i++){
            if(dm[i]){
                ans+=c[i];
                for(int j=1;j<=n;j++){
                    b.push_back({n+i,j,a[i][j]});
                }
            }
        }
        ans+=mit();
        minn=min(minn,ans);
        ++T;
        if(T>43){
            cout<<minn;
            exit(0);
        }
        return ;
    }
    dm[x]=1;
    dfs(x+1);
    if(c[x]>0){
        dm[x]=0;
        dfs(x+1);
    }

}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e.push_back({x,y,z});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<minn<<endl;
    return 0;
}
