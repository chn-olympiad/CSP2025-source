#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int to,w;
};
vector <node> e[10005];

struct VAL{
    int c;
    int a[10005];
};
VAL qq[15];

struct edge{
    int x,y,w;
};

int a[15];
int n,m,k;

int f[10005];

int findf(int x){
    if(x==f[x]){
        return x;
    }

    return f[x]=findf(f[x]);
}

void mergef(int x,int y){
    f[findf(x)]=findf(y);
}

vector <edge> original;
vector <edge> getans;
vector <edge> eee;

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int CalcAns(){
    for(int i=1;i<=n+k+1;i++){
        f[i]=i;
    }

    getans=eee;
    int ret; ret=0;
    for(int i=1;i<=k;i++){
        if(a[i]){
            for(int j=1;j<=n;j++){
                getans.push_back({i+n,j,qq[i].a[j]});
            }
        }
    }

    sort(getans.begin(),getans.end(),cmp);

    for(int i=0;i<getans.size();i++){
        int l; l=getans[i].x;
        int r; r=getans[i].y;
        int w; w=getans[i].w;
        //cout<<"w:"<<w<<"\n"<<endl;

        if(findf(l)!=findf(r)){
            mergef(l,r);
            ret+=w;
        }
    }

    return ret;
}

int ret;
int ans;
void dfs(int choose,int pre){
    if(choose==k){
        ret=min(CalcAns()+pre,ret);
        return;
    }

    dfs(choose+1,pre);
    a[choose+1]=1;
    dfs(choose+1,pre+qq[choose+1].c);
    a[choose+1]=0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        original.push_back({u,v,w});
    }

    for(int i=1;i<=k;i++){
        int c; cin>>c;
        qq[i].c=c;

        for(int j=1;j<=n;j++){
            cin>>qq[i].a[j];
        }
    }

    sort(original.begin(),original.end(),cmp);

    for(int i=1;i<=n;i++){
        f[i]=i;
    }

    ans=0;

    for(int i=0;i<original.size();i++){
        int l; l=original[i].x;
        int r; r=original[i].y;
        int w; w=original[i].w;

        if(findf(l)!=findf(r)){
            mergef(l,r);
            eee.push_back({l,r,w});
            ans+=w;
        }
    }

    //cout<<ans<<endl;
    ret=ans;
    dfs(0,0);
    cout<<ret<<"\n";
    return 0;
}

/*
O((kn)log(kn)*(2^k)) 1e9...
road4.in 0.6s (w/ O2)
road3.in 0.9s (w/ O2)
AC byebye
*/
