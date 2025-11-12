#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef long long ll;
using namespace std;
const ll maxn=ll(1e4+5);


struct node{
    ll u;
    ll v,w;
    /*bool operator<(const node& a){
        return w<a.w;
    }*/
};

bool operator<(node b,node a){
    return b.w>a.w;
}

ll fa[maxn];
priority_queue <node> li;
vector <node> graph[maxn];

vector <ll> village[11];
ll cvill[11];

ll find(ll x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void hebei(ll a,ll b){
    ll faa=find(a);
    ll fab=find(b);
    fa[faa]=fab;
    return ;
}

ll read(){
    ll igt=0,sgn=1;
    char c=getchar();
    while(c<'0' or c>'9'){
        if(c=='-'){
            sgn=-1;
        }
        c=getchar();
    }
    while(c>='0' and c<='9'){
        igt=(igt<<3)+(igt<<1)+c-'0';
        c=getchar();
    }
    return igt*sgn;
}


ll n,m,k;
ll gogogo(ll typ){
    for(ll i=1;i<=n;i++){
        fa[i]=i;
    }
    bool isis[11];
    memset(isis,0,sizeof(isis));
    ll bi=1;
    while(typ){
        isis[bi]=(typ%2);
        typ/=2;
        bi++;
    }

    priority_queue <node> lis(li);
    ll ans=0;
    for(ll i=1;i<=k;i++){
        if(isis[i]==1){
            ans+=cvill[i];
            for(ll j=1;j<=n;j++){
                for(ll k1=j+1;k1<=n;k1++){
                    lis.push({j,k1,village[i][j-1]+village[i][k1-1]});
                }
            }
        }
    }

    while(!lis.empty()){
        node tmp=lis.top();
        lis.pop();
        if(find(tmp.u)!=find(tmp.v)){
            ans+=tmp.w;
            hebei(tmp.u,tmp.v);
        }
    }
    return ans;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();

    for(ll i=1;i<=m;i++){
        ll u=read(),v=read(),w=read();
        node tmp;
        tmp.v=v;tmp.w=w;
        tmp.u=u;
        graph[u].push_back(tmp);
        li.push(tmp);
        tmp.v=u;tmp.u=v;
        graph[v].push_back(tmp);
    }

    for(ll i=1;i<=k;i++){
        cvill[i]=read();
        for(ll j=1;j<=n;j++){
            ll tmp=read();
            village[i].push_back(tmp);
        }
    }
    ll ret=0x3f3f3f3f;

    for(ll i=0;i<(1<<k);i++){
        ret=min(ret,gogogo(i));
    }
    cout<<ret;
    return 0;
}
