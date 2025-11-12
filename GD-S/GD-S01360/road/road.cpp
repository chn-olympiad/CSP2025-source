#include<bits/stdc++.h>
using namespace std;
int n,m,k,mp[10100][10100],a[200010],sum=0,b[200010],c[200010];
bool vis[200010];

void dp(int i){
	int s=1e9+1,y=0;
	for(int j=1;j<=n;j++){
		if(j==i) continue;
		if(mp[i][j]<s&&mp[i][j]!=0&&vis[j]==0){
//	cout<<i<<"->"<<j<<":"<<mp[i][j]<<" ";
			s=mp[i][j];
			y=j;
		}
		if(mp[i][j]!=0&&mp[i][j]<a[j]&&vis[j]==0){
	
			a[j]=mp[i][j];
	//	cout<<"a["<<j<<"]="<<a[i]<<endl;
		}
	}
	//cout<<endl;
	if(y==0) return;
//	cout<<"y:"<<y<<" "<<endl;
	vis[y]=1;
	dp(y);
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,1e9+1,sizeof(a));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[j];
		}
	}
	a[1]=0;
	vis[1]=1;
	dp(1);
	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
		sum+=a[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
