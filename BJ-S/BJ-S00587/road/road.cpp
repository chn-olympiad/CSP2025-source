#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N=1e4+100,M=2e6+100;
typedef pair<int,int> PII;

struct node {
    int a,b,c;
};

int n,m,k;
int c[N],p[N];
vector<node> edge;

int find(int x) {
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

bool cmp(node a,node b) {
    return a.c<b.c;
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }
    for(int j=1;j<=k;j++) {
        cin>>c[j];
        vector<pair<int,int>> d;
        int check=0;
        for(int i=1;i<=n;i++) {
            int c;
            cin>>c;
            if(c==0) check=i;
            d.push_back({i,c});
        }
        for(auto v:d) edge.push_back({check,v.first,v.second});
    }
    sort(edge.begin(),edge.end(),cmp);
    int cnt=0,ans=0;
    for(int i=0;i<edge.size();i++) {
        int u=find(edge[i].a),v=find(edge[i].b),w=edge[i].c;
        if(u==v) continue;
        cnt++,p[u]=v,ans+=w;
        if(cnt==n-1) break;
    }
    cout<<ans<<"\n";
}