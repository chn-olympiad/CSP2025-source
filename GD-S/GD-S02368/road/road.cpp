#include<bits/stdc++.h>
using namespace std;
const int N=100010; 
int n,m,k;
int mp[10050][10050];
int d[N];
int vis[N];
int q[20];
int p[20];
int ans;
void f(){
	for(int i=1;i<=n+k;i++)d[i]=1e9;
	d[1]=0;
	for(int step=1;step<=n+k;step++){
		int mi=1e9,id=-1;
		for(int i=1;i<=n+k;i++)if(!vis[i]){
			int tmp=0;
			if(i>n){
				tmp=(!p[i])*q[i-n];
			}
			if(d[i]+tmp<mi){
				mi=d[i]+tmp;
				id=i;
			}
		}
		if(step>n&&id>n)break;
		vis[id]=1;
		ans+=mi;
		if(id>n){
			p[id]=1;
		}
		for(int i=1;i<=n+k;i++)if(!vis[i]&&d[i]>mp[id][i]){
			d[i]=mp[id][i];
		} 
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		mp[x][y]=mp[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>q[i];
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			mp[n+i][j]=mp[j][n+i]=t;
		}
	}
	f();
	return 0;
} 
