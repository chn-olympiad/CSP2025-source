#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
struct node{
	int toone,totwo,diss;
};
bool cmp(node x,node y){
	return x.diss<y.diss;
}
int tot;
node dis[2000005];
int a[15][20005];
bool vis[15];//town
int buildtown[15];// c
long long ans;
int fa[20005];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
long long anscnt=1e15;
void make_itt(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=tot;i++){
		int toonee=dis[i].toone,totwoo=dis[i].totwo;
		if(!vis[toonee>n?toonee-n:0]||!vis[totwoo>n?totwoo-n:0])continue;
		int fx=find(toonee);
		int fy=find(totwoo);
//		cout<<fx<<" "<<fy<<" "<<toonee<<" "<<totwoo<<"\n";
		if(fx!=fy){
			ans+=dis[i].diss;
			fa[fx]=fy;
		}
	}
}
void dfs(int x){
	if(x>k){
		ans=0;
//		cout<<"make_type : ";//
		for(int i=1;i<=k;i++){
			if(vis[i]==1)ans+=buildtown[i];
//			cout<<vis[i];//
		}
//		cout<<"\n";//
		make_itt();
//		cout<<" ans : "<<ans<<"\n";//
		if(ans<anscnt)anscnt=ans;
		return ;
	}
	vis[x]=0;
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
	return ;
}
bool flag=1; 
signed main(){
//	freopen("road2.in","r",stdin);
//	freopen("road2.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	vis[0]=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		dis[++tot]=(node){x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>buildtown[i];
		if(buildtown[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			dis[++tot]=(node){n+i,j,a[i][j]};
		}
	}
	sort(dis+1,dis+tot+1,cmp);
//	for(int i=1;i<=tot;i++){
//		cout<<dis[i].toone<<" "<<dis[i].totwo<<" "<<dis[i].diss<<"\n";
//	}
//	cout<<"vis[i]_size : \n";//
//	for(int i=1;i<=n+k;i++){//
//		cout<<v[i].size()<<" ";//
//	}//
//	cout<<"\n";//
	if(flag){
		for(int i=1;i<=k;i++)vis[i]=1;
		make_itt();
		anscnt=ans;
	}
	else dfs(1);
	cout<<anscnt;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
