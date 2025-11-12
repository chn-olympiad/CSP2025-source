//GZ-S00242	贵阳市第三实验中学	李金泽 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int u[1000010],v[1000010],w[1000010];
int c[20],a[20][10010];
int vis[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			if(i==0){
				cin>>c[j];
			}else{
				cin>>a[j][i];
			}
		}
	}
	cout<<ans/2+1;
	return 0;
}
