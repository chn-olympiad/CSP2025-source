//GZ-S00182 贵阳市云岩区中天中学 张颜淏
 #include<bits/stdc++.h>
using namespace std;
const int N=5e3+15;
int a[N][N];
bool vis[N][N];
int n,k,m,countryside_num=0;
int u,v,w;
long long mm=LONG_LONG_MAX;
void dfs(int cities,long long money,int nowc){
	if(cities==n+countryside_num){
		mm=min(mm,money);
		return;
	}
	for(int i=1;i<=n+k;i++){
		if(!vis[nowc][i]&&i!=nowc&&a[nowc][i]!=0){
			vis[nowc][i]=1;
			vis[i][nowc]=1;
			if(i>n)countryside_num++;
			dfs(cities+1,money+a[nowc][i],i);
			if(i>n)countryside_num--;
			vis[nowc][i]=0;
			vis[i][nowc]=0;
		}
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	int mc=INT_MAX;
	for(int i=1;i<=k;i++){
		cin>>m;
		mc=min(mc,m);
		for(int j=1;j<=n;j++){
			cin>>w;
			a[i+n][j]=w+m;
			a[j][i+n]=w+m;
		}
	}
	dfs(1,0,1);
	cout<<mm-mc;
	return 0;
}
