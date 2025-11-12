#include<bits/stdc++.h>
using namespace std;
int mp[10010][10010];
int d[10010];
int vis[10010];
int a[10010];
int n,m,k;
void di(){
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	for(int i=1;i<=n;i++){
		int x=0x3f3f3f3f,y;
		for(int j=1;j<=n;j++){
			if(d[j]<x&&!vis[j]){
				x=d[j];
				y=j;
			}
		}
		vis[y]=1;
		if(x==0x3f3f3f3f) break;
		for(int i=1;i<=n;i++){
			d[i]=min(d[i],mp[y][i]);
			//cout<<"hehehhehe "<<i<<" "<<d[i]<<endl;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	di();
	int ans=0,maxn=0;
	for(int i=1;i<=n;i++){
		ans+=d[i];
		maxn=max(maxn,d[i]);
	}
	//cout<<"heheh "<<ans<<endl;
	int minx=ans;
	int TF=1;
	for(int i=1;i<=k;i++){
		int min1=0x3f3f3f3f,min2=0x3f3f3f3f;
		int t;
		cin>>t;
		int cnt=ans+t;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			if(x!=0) TF=0;
			if(x<min1){
				min1=x;
				min2=min1;
			}else if(x<min2){
				min2=x;
			}
		}
		minx=min(minx,cnt-maxn+min1+min2);
	}
	if(TF==1){
		cout<<0;
		return 0;
	}
	cout<<minx;
	return 0;
}
