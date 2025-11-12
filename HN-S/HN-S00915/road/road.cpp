#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m,k,b[11451],idx,c[11451],a[11][11451],tot,b2[11451];
long long ans=LLONG_MAX,sum,sum2,sum1,d2[11451];
vector<pii> e[11451];
inline void Prim(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    b2[1]=idx;
    while(!pq.empty()){
        pii t=pq.top();
        pq.pop();
        int x=t.se;
        if(b[x]==idx){
            continue;
        }
        //cout << x << ' ' << d2[x] << '\n';
        sum2+=d2[x];
        b[x]=idx;
        for(auto i:e[x]){
            sum++;
            //cout<<i.fi << ' ' << i.se <<'\n';
            if(d2[i.fi]>i.se||b2[i.fi]<idx){
                d2[i.fi]=i.se;
                b2[i.fi]=idx;
                pq.push({d2[i.fi],i.fi});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    tot=n+k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    int i2=1;
    for(int i=1;i<=k;i++,i2++){
            bool flag=1,flag2=1;
        cin>> c[i2];
    if(c[i]!=0){flag=0,flag2=0;}
        for(int j=1;j<=n;j++){
            cin >> a[i2][j];
            if(a[i2][j]!=0)flag=0;
        }
        if(flag){cout << 0;
        return 0;}
    }
    for(int i=0;i<(1<<k);i++){
    for(int j=1;j<=k;j++){
    if((i>>(j-1))&1){
    sum1+=c[j];
    for(int i=1;i<=n;i++){
      //  for(int i=1;i<=n;i++){cout<< nxt[i] << ' ';}
    //cout<< '\n';
        e[j+n].push_back({i,a[j][i]});
        e[i].push_back({j+n,a[j][i]});
    }
    }
    }
    //cout <<"目前为止一切正常";
    sum2=0;
    idx++;
    Prim();
    //cout<< sum2 <<' ' <<sum1 << '\n';
    ans=min(ans,sum2+sum1);
    for(int j=1;j<=k;j++){
    if((i>>(j-1))&1){
    for(int i=n;i>=1;--i){
            //sum++;
        e[i].pop_back();
    }
    e[j+n].clear();
    sum1-=c[j];
    }
    }
    //for(int i=1;i<=n;i++){cout<< nxt[i] << ' ';}
    //cout << tot <<'\n';
    //cout <<"111\n";
    }
    cout<< ans;
    return 0;
}
