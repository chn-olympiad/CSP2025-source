#include<bits/stdc++.h>
using namespace std;

struct Road{
    int a,b,spend;
};
vector<Road> roads;
vector<int> link;
int n,m,k;

bool sr(Road a,Road b){
    return a.spend<b.spend;
}

int head(int a){
    if(link[a]==a)
        return a;
    link[a]=head(link[a]);
    return link[a];
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    roads.reserve(m);
    for(int i=0;i<m;++i){
        Road r;
        cin>>r.a>>r.b>>r.spend;
        roads.push_back(r);
    }

    for(int i=1;i<=k;++i){
        int c;
        cin>>c;
        for(int j=1;j<=n;++j){
            Road r;
            cin>>r.spend;
            r.a=n+i;
            r.b=j;
            roads.push_back(r);
        }
    }

    sort(roads.begin(),roads.end(),sr);

    link=vector<int>(n+1);
    for(int i=1;i<=n;++i)
        link[i]=i;

    int re=n-1,spe=0;
    for(int i=0;i<roads.size()&&re;++i){
        link[roads[i].a]=head(roads[i].b);
        spe+=roads[i].spend;
        --re;
    }

    cout<<spe;

    return 0;
}
