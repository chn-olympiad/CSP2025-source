#include<bits/stdc++.h>
using namespace std;
void testread(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
}
int n,m,k;
pair<int,pair<int,int>>e[1000010];
int bel[10010],fa[10010],nxt[10010];
int c[20][10010];
int findfa(int x){
    if(fa[x]!=x)return findfa(fa[x]);
    else return fa[x];
}
int g[10010];
vector<int>flg;
vector<int>rev;
bool flag[10010];
signed main(){
    testread();
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++)cin>>e[i].second.first>>e[i].second.second>>e[i].first;
        for(int i=1;i<=k;i++)for(int j=0;j<=n;j++)cin>>c[i][j];
        sort(e+1,e+1+m);
        for(int i=1;i<=n+k;i++)fa[i]=i;
        int sum=0;
        int siz=0;
        for(int i=1;i<=m;i++){
            if(findfa(e[i].second.first)!=findfa(e[i].second.second)){
                fa[findfa(e[i].second.first)]=e[i].second.second;
                sum+=e[i].first;
                siz++;
                g[siz]=i;
            }
        }
        //cout<<sum<<endl;
        for(int i=1;i<=k;i++){
            rev.clear();
            flg.clear();
            int des=0,cost=c[i][0];
            int mn=2147483647,mnedge=0;
            for(int j=1;j<n;j++){
                int edg=g[j];
                if(flag[j])continue;
                if(e[edg].first>min(c[i][e[edg].second.first],c[i][e[edg].second.second])){
                    cost+=min(c[i][e[edg].second.first],c[i][e[edg].second.second]);
                    des+=e[edg].first;
                    flg.push_back(i);
                    if(mn>e[edg].first)mn=e[edg].first,mnedge=j;
                    if(c[i][e[edg].second.first]<c[i][e[edg].second.second])
                        rev.push_back(fa[e[edg].second.first]),fa[e[edg].second.first]=n+i;
                    if(c[i][e[edg].second.first]>=c[i][e[edg].second.second])
                        rev.push_back(fa[e[edg].second.second]),fa[e[edg].second.second]=n+i;
                }
            }
            for(int j=1;j<=n;j++){
                if(findfa(j)!=n+i){
                    if(mn>c[i][j])mn=c[i][j],mnedge=-1;
                }
            }
            cost+=mn;
            if(cost<des){
                sum=sum+cost-des;
                for(auto j:flg){
                    if(j!=mnedge)flag[j]=1;
                }
            }else{
                for(int j=0;j<flg.size();j++){
                    int edg=g[j];
                    if(c[i][e[edg].second.first]<c[i][e[edg].second.second])fa[e[edg].second.first]=rev[j];
                    if(c[i][e[edg].second.first]>=c[i][e[edg].second.second])fa[e[edg].second.second]=rev[j];
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

