#include<iostream>
#include<vector>
using namespace std;
int n,m,k,ans,num;
struct node{
	int v,w;
};
int mp[10015][10015];
bool ok[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int r;
			cin>>r;
			mp[n+i][j]=r+c;
			mp[j][n+i]=r+c;
			if(r==0){
				ok[j]==1;
			}
		}
	}
	num=n+k;
	for(int i=1;i<=n;i++){
		if(!ok[i]){
			int tot=2147473647;
			for(int j=1;j<=num;j++){
				//cout<<mp[i][j]<<" ";
				if(!mp[i][j]){
					mp[i][j]=2147483647;
				}
				//cout<<mp[i][j]<<endl;
				tot=min(mp[i][j],tot);
				//cout<<tot<<endl;
			}
			ans+=tot;
		}
	}
	cout<<ans;
	return 0;
}
