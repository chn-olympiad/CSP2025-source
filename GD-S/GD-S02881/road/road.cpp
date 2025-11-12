#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mp[10005][10005],c[15],a1[15][10005],last=0,a[15],x,b,y;
bool vis[15],z[10005][10005];
struct node{
	int x,y;
};
queue<node>q;
void bfs(int x,int y){
	
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>b>>y;
		mp[x][b]=y;
		mp[b][x]=y;
		z[x][b]=true;
		z[b][x]=true;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>mp[n+i][j];
			mp[j][n+i]=mp[n+i][j];
		}
	}
	k+=n;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i+3-n;j++){
			if(z[i][j]){
				long long cnt=10000000000,cn;
				for(int l=1;l<=k-n;l++){
					if(vis[l]){
						a[l]=mp[n+l][i]+mp[n+l][j];
					}else{
						a[l]=mp[n+l][i]+mp[n+l][j]+c[l];
					}
					cnt=min(a[l],cnt);
					if(min(a[l],cnt)==a[l]){
						cn=l;
					}
				}
				cout<<last+mp[i][j]<<" "<<last+cnt<<endl;
				last=min(last+mp[i][j],last+cnt);
				if(min(mp[i][j],cnt)==cnt){
					vis[cn]=true;
				}
			}	
		}
	}
	cout<<last;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
