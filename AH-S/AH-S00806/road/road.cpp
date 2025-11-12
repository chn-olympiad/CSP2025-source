#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct road{
    int e,w;
};
vector<road> a[100005];
int dis[100005];
bool vis[100005];
const int INF=0x3fffffff;
void dfs(int x){
    for(int ii=1;ii<=n;ii++){
        int maxn=INF;
    int flag=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&dis[i]<maxn){
            maxn=dis[i];
            flag=i;
        }
    }
    if(flag==-1)continue;
    ans+=maxn;
    vis[flag]=true;
    for(int i=0;i<a[flag].size();i++){
        if(dis[a[flag][i].e]>a[flag][i].w){
            dis[a[flag][i].e]=a[flag][i].w;
        }
    }
    }

}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
        dis[i]=INF;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        road aa;
        aa.e=v;
        aa.w=w;
        a[u].push_back(aa);
        aa.e=u;
        aa.w=w;
        a[v].push_back(aa);
	}
int ss[10005];
	for(int i=1;i<=k;i++){

        cin>>ss[1];


       for(int j=1;j<=n;j++){
            cin>>ss[i];
          // cout<<j<<' ';
        }
        for(int j=1;j<=n;j++){
            for(int jj=1;jj<=n;jj++){
                    road aa;
                aa.e=jj;
                aa.w=ss[j]+ss[jj];
                a[j].push_back(aa);
            }
        }


	}dis[1]=0;
        dfs(1);
        cout<<ans;
	return 0;
}

