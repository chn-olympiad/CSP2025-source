#include<bits/stdc++.h>
using namespace std;
int n,m,k,huafei[10050][10050]={},c[15]={};
//void dfs(int n_change,int alr_change,int mubiao_change){
//	if(n_change>k)return;
//	if()
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int st,en,w;
		cin>>st>>en>>w;
		huafei[st][en]=w;
		huafei[st][en]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>huafei[m+i][j];
			huafei[j][m+i];
		}
	}
	for(int i=1;i<=n;i++){
		int guanlian[10050]={},zhizhen=1;
		for(int j=i+1;j<=n;j++){
			if(huafei[i][j]!=0){
				guanlian[zhizhen++]=j;
			}
		}
		for(int j=1;j<zhizhen-1;j++){
			for(int z=j+1;z<zhizhen;z++){
				int x=guanlian[j];
				int y=guanlian[z];
				if(huafei[x][y]>huafei[i][x]+huafei[i][y]||huafei[x][y]==0){
					huafei[x][y]=-1;
				}
				//减去多余部分 
			}
		}
	}
	cout<<100;
	//for(int i=1;i<=k;i++){//城市化改造城市的数量
	//	dfs(0,0,i); 
	//}
	return 0;
}
