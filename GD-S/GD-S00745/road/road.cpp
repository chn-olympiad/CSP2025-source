#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool dian[10005];
int nn[10005]={0};
int kw1[15]={0};  //乡村的价格 
int kw2[15][10005]={0};//修乡村与城市的路 
long int ans=114154,cost=0;
struct r{
	int u,v,w;
};
r ro[10005];
bool flag[10005];
void dfs(int k){
	if(k==n-1){
		if(ans>cost){
			bool che=true;
			for(int i=1;i<=n;i++){
				if(!dian[i]){
					che=false;i=n;
				}
			}
			if(che){
				ans=cost;
			}
		}
	}else{
		if(cost>=ans)return;
		for(int i=1;i<=m;i++){
			if(!flag[i]){
				cost+=ro[i].w;
				flag[i]=true;
				bool rec1,rec2;
				
				if(dian[ro[i].u]) rec1=false;
				else rec1=true;dian[ro[i].u]=true;
				if(dian[ro[i].v]) rec2=false;
				else rec2=true;dian[ro[i].v]=true;
				
				dfs(k+1);
				cost-=ro[i].w;
				flag[i]=false;
				if(rec1)dian[ro[i].u]=false;
				if(rec2)dian[ro[i].v]=false;
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>ro[i].u>>ro[i].v>>ro[i].w;
		flag[i]=false;
		dian[i]=false;
	}
	bool shi0=true;
	if(k==0)shi0=false;
	for(int i=1;i<=k;i++){
		cin>>kw1[i];
		if(shi0&&kw1[i]!=0)shi0=false;
		for(int j=1;j<=n;j++){
			cin>>kw2[i][j];
			if(shi0&&kw2[i][j]!=0)shi0=false;
		}
	}
	if(shi0)cout<<0;
	else{
		dfs(0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
