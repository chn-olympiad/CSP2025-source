#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,ans,t;
int a[10011][10011];
bool f[10011][10011];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		a[u][v]=w,a[v][u]=w;
	}
	for(int i=n+1;i<n+k+1;i++){
		int c;
		cin>>c;
		for(int l=1;l<=m;l++){
			int j;
			cin>>j;
			a[l][i]=c+j,a[i][l]=c+j;
		}
	}
	int N=n,h=1;
	while(N--){
		int l=1;
		while(a[h][l]==0 || f[h][l]==1) l++;
		for(int x=1;x<n+k+1;x++){
			if(!a[h][x] || f[h][x]) continue;
			else if(a[h][l]>a[h][x]){
				for(int o=1;o<n+k+1;o++){
					f[o][h]=1;
				} 
				l=x;
			}
		} //找出h行最小的数所在列l 
		ans+=a[h][l];
		h=l;
	}
	cout<<ans-1;
	return 0;
} 
