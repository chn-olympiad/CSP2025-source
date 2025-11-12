#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define PII pair<int,int>
#define ll long long
const int M=1e6+10;
const int N=1e4+10;
const int K=11;
int n,m,k;
int c[N],a[K][N];

bool build[K];
priority_queue<PII> d;

vector<PII> ee[N];

struct edge{
    int u,v,w,ne=0;
    bool vis;
}e[2*M];
int h[N],cnt=0;
void adde(int uu,int vv,int ww,int vii){
    e[++cnt]={uu,vv,ww,h[uu],1};
    h[uu]=cnt;
}
ll res;
int vised[N];
ll prim(){//start=1
    ll ans=0;
    int u=1;
    vised[u]=1;
    for(int i=1;i<n;i++){
        ans-=d.top().first;
        d.pop();
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    int tu,tv,tw;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&tu,&tv,&tw);
        adde(tu,tv,tw,1);

        d.push({-tw,i});
    }//(1~2*m)


    bool flag=1;
   for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]) flag=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]) flag=0;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }
    ll ans=0;
    ll res=LLONG_MAX;
    ans=prim();
    for(int t=0;t<(1<<k);t++){
        for(int i=0;i<k;i++){
            build[i+1]=(t>>i&1);
            if(t>>i&1){
                ans+=c[i+1];
            }
        }
        ans+=prim();
        res=min(ans,res);
    }
    printf("%lld",res);
    return 0;
}
