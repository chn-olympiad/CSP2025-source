#include<bits/stdc++.h>
using namespace std;
int n,m,k;//城市数量，道路数量，准备进行城市化的乡镇数量
struct node{
	int u,v;//这条道路连接的两座城市 
	int w;//修建道路的费用 
}road[1000001];
struct abc{
	int c;//进行城市化改造的费用 
	int a[1000001];//到第a[i]座城市修建道路的费用 
}city[1000001];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].u>>road[i].v>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>city[i].c;
		for(int j=1;j<=n;j++){
			cin>>city[i].a[i];
		}
	}
	return 0;
}
