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
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        e.push_back({x,y,z});
    }
    bool f=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ans=2e18;
    for(int i=0;i<(1<<(k-1));i++){
        b.clear();
        int cnt=0;
        for(int j=1;j<=k;j++){
            if(i>>(j-1)&1){
                cnt+=c[i];
                for(int j=1;j<=n;j++){
                    b.push_back({n+i,j,a[i][j]});
                }
            }
        }
        ans=min(ans,cnt+mit());
    }
    cout<<ans<<endl;
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
