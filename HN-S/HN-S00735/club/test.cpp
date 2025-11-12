#include<bits/stdc++.h>
using namespace std;
#define mxn 500010
#define ll long long
#define pb push_back
#define pii pair<int,int>
int n,a[mxn][4],c;
int s,t,val[mxn],fl[mxn];
ll flp[mxn];
ll maxc,maxf,dis[mxn];
pii lst[mxn];
bool inq[mxn];
vector<pii> g[mxn];
void addedge(int st,int ed,int v,int f){
    g[st].pb({ed,++c});
    val[c]=-v,fl[c]=f;
    g[ed].pb({st,++c});
    val[c]=v,fl[c]=0;
}
queue<int> q;
bool spfa(){
	int u;
    for(int i=0;i<g[u].size();i++){
    	pii j=g[u][i];
	}
    if(dis[t]>=1e12)return 0;
    return 1;
}
void dfs(){
    int nw=t;ll nflow=flp[t],cst=0;
    while(nw!=s){
        auto [u,nm]=lst[nw];
        fl[nm]-=nflow,fl[nm^1]+=nflow;
        cst+=nflow*val[nm];
    }
    maxf+=nflow,maxc+=cst;
}
void ek(){while(spfa())dfs();}
void solve(){
    maxf=maxc=0;
    cin>>n,c=1;
    s=n+4,t=n+5;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        addedge(s,i,0,1);
        addedge(i,n+1,a[i][1],1);
        addedge(i,n+2,a[i][2],1);
        addedge(i,n+3,a[i][3],1);
    }
    addedge(n+1,t,0,n/2);
    addedge(n+2,t,0,n/2);
    addedge(n+3,t,0,n/2);
    ek();
    cout<<maxc<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    // freopen("club.in","r",stdin);
    // freopen("club.out","w",stdout);
    int T;cin>>T;while(T--)solve();
    return 0;
}
//-static-libgcc
