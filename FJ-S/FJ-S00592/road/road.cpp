#include<bits/stdc++.h>

using namespace std;
int a[1010][1010],co[20][1010];//邻接表 
bool used1[1010],used2[20];//看是否已联通 

int n,m,k;
int ans = 999999999;

void dfs(int now,int dj,bool cz){//dj代价 
	
	if(used1[now] && cz == 1)return;//来过城市 
	if(dj >= ans)return;//代价比现有答案大 
	
	int ndj = dj;
	if(cz)used1[now] = 1;
	else if(!used2[now]){
		
		dj += co[now][0];//城镇化费用
		
	}
	
	if(!cz){
		
		bool lt = 1;
		for(int i=1;i<=n;i++){
			if(!used1[i])lt = 0;
		}
		if(lt){
			
			ans = dj;
			return;
			
		}
	}//如果是乡村,就查一下是否都联通了 
	
	for(int i=1;i<=a[now][0];i++){
		
		dfs(i,dj+a[now][i],1);
		
	}//遍历每一条路 
	
	if(cz){
		for(int i=1;i<=n;i++){
		
			dfs(i,dj+co[now][i],1);
		
		}//遍历每一个乡村
	} 
		
	used1[now] = 0; 
	
}

int main(){

	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(a,-1,sizeof(a));
	memset(co,-1,sizeof(co));
	
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		
		int u,v,w;
		cin>>u>>v>>w;
		
		a[u][0]++;
		a[v][0]++;
		a[u][v] = w;
		a[v][u] = w;
		
	}//输入城镇
	
	for(int j=0;j<k;j++){
		
		cin>>co[j][0];//改造费用 
		for(int i=1;i<=n;i++){
			
			cin>>co[j][i];
			
		}
		
	}//输入乡村 
	
	dfs(1,0,1);
	
	cout<<ans; 
	
	return 0;
}

