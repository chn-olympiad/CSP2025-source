//GZ-S00178 贵阳市华师一学校 张金畅
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
int n,m,k,u,v,w,a[N][N],b[N],c[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int x;
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			c[i][j]+=x;
			c[j][i]=c[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		} 
		cout<<endl;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cout<<c[i][j]<<" ";
		} 
		cout<<endl;
	}
	return 0;
}
