#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+20;
const ll inf=1e18;
int n,m,k,fa[N],d[15];
ll ans;
struct edge{
    int x,y,z;
};
bool cmp(edge a,edge b){
    return a.z<b.z;
}
vector<edge> v[15],w[1024];
int Find(int x){
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        w[0].push_back((edge){a,b,c});
    }
    sort(w[0].begin(),w[0].end(),cmp);
    for(int i=1;i<=k;i++){
        cin>>d[i];
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            v[i].push_back((edge){n+i,j,x});
        }
        sort(v[i].begin(),v[i].end(),cmp);
    }
    ans=inf;
    for(int i=0;i<(1<<k);i++){
        int lenp,lenq,p,q,cnt=n-1,len;
        bool flag=0;
        ll sum=0;
        for(int j=0;j<k;j++){
            if((i>>j)&1){
                cnt++;
                sum+=d[j+1];
                if(flag) continue;
                flag=1;
                int t=i^(1<<j);
                lenp=(int)w[t].size(),lenq=(int)v[j+1].size(),p=q=0;
                while((p<lenp)||(q<lenq)){
                    if(p==lenp) w[i].push_back(v[j+1][q]),q++;
                    else if(q==lenq) w[i].push_back(w[t][p]),p++;
                    else if(w[t][p].z<=v[j+1][q].z) w[i].push_back(w[t][p]),p++;
                    else w[i].push_back(v[j+1][q]),q++;
                }
            }
        }
        len=(int)w[i].size();
        for(int j=1;j<=n+k;j++) fa[j]=j;
        vector<edge> vt;
        for(int j=0;j<len&&cnt;j++){
            int a=w[i][j].x,b=w[i][j].y,c=w[i][j].z;
            int faa=Find(a),fab=Find(b);
            if(faa!=fab){
                fa[faa]=fab;
                cnt--;
                sum+=c;
                vt.push_back(w[i][j]);
            }
        }
        w[i].clear();
        len=(int)vt.size();
        for(int j=0;j<len;j++) w[i].push_back(vt[j]);
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}