#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,k,ans,a[15][N];
struct str{
    int v,w;
};
vector<str> G[N];
int c[15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        ans+=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j].v,w=G[i][j].w;
			for(int l=1;l<=k;l++){
				if(c[l]+a[l][i]+a[l][v]<w){
					ans-=w-(c[l]+a[l][i]+a[l][v]);
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
