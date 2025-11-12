//GZ-S00324 六盘水市第四实验中学 王梓懿 
#include<bits/stdc++.h>
using namespace std;
const int N=1000000010;
int k,s,sum,c[N],m,n,u[N],v[N],w[N],a[N][N];
bool vis[N];
//n座城市 m条路 城市 ui 和 vi
//k个准备进行城市化改造的乡镇
//修复第i(1≤i≤m)条道路的费用为wi;
//座城市间建造一条道路的费用为 aj,i。

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		memset(vis,0,m);
		sum=0;
		for(int j=1;j<=m;j++){
			if(j==1){
				vis[i]=1;
			} if(vis[u[j]]==1){
				vis[v[j]]=1;
				sum+=w[i];
			}
		}
		if(s=0)s=sum;
		else if(s>sum)s=sum;
	}
	cout<<s;
	return 0; 
}
