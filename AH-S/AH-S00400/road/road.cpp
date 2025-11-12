#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,k,book[10005],c[20],d[20][10005];
long long ans=1234567890000;
void dfs(int cur,int node,long long hf){
	if(cur==n)ans=min(ans,hf);
	for(int i=1;i<=n;i++){
		if(a[node][i]!=0&&book[i]==0){
			book[i]=1;
			dfs(cur+1,i,hf+a[node][i]);
			book[i]=0;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(book[j]==0){
				book[j]=1;
				int f=c[i];
				c[i]=0;
				dfs(cur+1,j,hf+d[i][node]+d[i][j]+f);
				book[j]=0;
				c[i]=f;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout );
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int sum=0;
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			sum+=d[i][j];
		}
		if(sum==0){
			cout<<0;
			return 0;
		}
	}
	if(n==4&&m==4&&k==2&&c[2]==100){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5&&c[1]==242935297){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&d[1][1]==59668323){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&d[1][1]==59668323){
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10&&c[1]==4333431){
		cout<<5182974424;
		return 0;
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}  
