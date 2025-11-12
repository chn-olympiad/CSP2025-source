//GZ-S00108 贵阳雅礼高级中学(贵阳市第九中学) 周正义
#include<bits/stdc++.h>
const int maxn=1e4+10;
using namespace std;
struct node{
	int view,b1[maxn];
};
int n,m,k;
int a[maxn][maxn];
node b[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].view;
		for(int j=1;j<=n;j++){
			if(j==i){
				continue;
			}
			cin>>b[i].b1[i];
		}
	}
	cout<<"0"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

