#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+5,M=1100,MM=1110005;
long long n,m,k,tot,A=1e18;
struct node{
    long long to,val,id;
};
struct node2{
    long long x,y,val,id;
};
vector<node>v[N+12],w[N+12];
vector<node2>e;
long long c[12],p[N],ans[M],XXX[MM],YYY[MM],VVV[MM];
node f[N];
set<long long>s[M];
bool cmp(node2 x,node2 y){
    return x.val<y.val;
}
bool cmp2(node x,node y){
    return x.val<y.val;
}
long long fin(long long x){
    if(p[x]==x)return x;
    return p[x]=fin(p[x]);
}
void ku(){
    for(long long i=1;i<=n;i++)p[i]=i;
    sort(e.begin(),e.end(),cmp);
    for(auto t:e){
        long long x=t.x,y=t.y;
        if(fin(x)==fin(y))continue;
        p[fin(x)]=fin(y);
        ans[0]+=t.val;
        s[0].insert(t.id);
    }
}
void dfs(node fa,long long x,long long g,long long h){
    f[x]=fa;
    for(auto t:w[x]){
        if(t.to==h)continue;
        dfs(t,t.to,g,x);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        e.push_back({x,y,z,++tot});
        //cout<<tot<<endl;
        XXX[tot]=x;
        YYY[tot]=y;
        VVV[tot]=z;
    }
    //return 0;
    ku();
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            long long x;
            cin>>x;
            v[i+n].push_back({j,x,++tot});
            XXX[tot]=i+n,YYY[tot]=j,VVV[tot]=x;
        }
        sort(v[i+n].begin(),v[i+n].end(),cmp2);
    }
    //ku();
    A=ans[0];
    for(long long i=1;i<(1<<k);i++){
        //cout<<i<<endl;
        long long t=i-(i&(-i)),t2=i&(-i),l=0;
        while(t2){
            l++;
            t2>>=1;
        }
        //cout<<i<<" "<<t<<endl;
        for(auto y:s[t])s[i].insert(y);
        ans[i]=ans[t]+c[l];
        node h=v[l+n][0];
        ans[i]+=h.val;
        s[i].insert(h.id);
        for(int i=1;i<=n+k;i++)w[i].clear();
        for(auto y:s[i]){
            w[XXX[y]].push_back({YYY[y],VVV[y],y});
            w[YYY[y]].push_back({XXX[y],VVV[y],y});
        }
        dfs({0,0,0},h.to,i,l+n);
    //cout<<"#"<<endl;
        for(long long j=1;j<n;j++){
            h=v[l+n][j];
            long long y=h.to;
            if(f[y].val>h.val){
                ans[i]-=f[y].val-h.val;
                s[i].erase(f[y].id);
                s[i].insert(h.id);
            }
        }
        //cout<<i<<" "<<ans[i]<<endl;
        /*
        cout<<"s[i]";
        for(auto t:s[i])cout<<t<<" ";
        cout<<endl<<"s2[i]";
        for(auto t:s2[i])cout<<t<<" ";
        cout<<endl;*/
        A=min(A,ans[i]);
    }
    cout<<A<<endl;
    return 0;
}
