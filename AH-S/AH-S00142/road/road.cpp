#include<bits/stdc++.h>
using namespace std;
int n,m,k,t[100005],u,v,w,vill[105],ok[100005],awa,a[15][100005];
vector<pair<int,int> >g[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>vill[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		ok[i]=1;
	}
	for(int id=1;id<=k;id++){
		int idx=0,ans=1e9;
		for(int i=1;i<=k;i++){
			//if(!ok[i])break;
			//int qwq=vill[i],mn=1e9;
			//int l=g[qwq].size();
			//for(int j=0;j<l;j++){
				//int to=g[qwq][j].first;
				//int val=g[qwq][j].second;
				//if(!ok[to])mn=min(mn,val);
			//}
			//if(mn<ans)ans=mn,idx=i;
		}
		ok[idx]=0;
		awa+=ans;
	}
	cout<<awa<<endl;
	return 0;
}
