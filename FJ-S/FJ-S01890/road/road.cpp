#include <bits/stdc++.h>
using namespace std;
const int N=1e5,M=1e7;

int n,m,k;
int u,v,w;
int c[12],a[12][N],sum;

int e[M],ne[M],ew[M],ecnt;
vector<int> h(N,-1),dis(N,1e9+5),dis2(N,1e9+5);
int scnt=1;
bool st[M];
void add(int u,int v,int w){
	e[ecnt]=v;
	ne[ecnt]=h[u];
	ew[ecnt]=w;
	h[u]=ecnt++;
}

void djst(){
	dis[1]=0;
	while(scnt<n){
		int minn=1e9+5,p;
		for(int i=1;i<=n;i++){
			if(!st[i]&&dis[i]<minn){
				p=i;
				minn=dis[i];
				scnt++;
				st[i]=1;
			}
		}
		for(int i=h[p];i!=-1;i=ne[i]){
			int t=e[i];
			dis[t]=min(dis[t],dis[p]+ew[i]);
		}
	}
}

int sk[N][30];//经过城镇就+1 
bool sk2[30];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	int fa=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) fa=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) fa=0;
		}
	}
	if(fa){//all free
		cout<<0<<endl;
		return 0;
	}
	
	djst();//shortest path
	for(int i=1;i<=n;i++){
		sum+=dis[i];
		//cout<<dis[i]<<endl;//不翻新时的价格 
	}
	if(k==0){
		cout<<sum<<endl;
		return 0;
	}
	
	for(int i=1;i<=k;i++){//加入新的结点后是否会导致dis减小 
		for(int j=1;j<=n;j++){
			add(i,j,a[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		st[i]=0;
		dis2[i]=dis[i];
		//cout<<dis2[i]<<' ';
	}
	for(int i=n+1;i<=n+k;i++){
		sk[i][i]=1;
	}
	scnt=0;
	dis2[1]=0;
	while(scnt<n+k){
		int minn=1e9+5,p;
		for(int i=1;i<=n+k;i++){
			if(!st[i]&&dis2[i]<minn){
				p=i;
				minn=dis2[i];
				scnt++;
				st[i]=1;
			}
		}
		for(int i=h[p];i!=-1;i=ne[i]){
			int t=e[i];
			dis2[t]=min(dis2[t],dis2[p]+ew[i]);
			if(dis2[t]<dis[t]){
				for(int j=1;j<=k;j++) sk[t][j]=sk[p][j];
			}
		}
	}
	
	int sum2=0;
	for(int i=1;i<=n+k;i++){
		sum2+=dis2[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(sk[i][j]) sk2[j]=1;
		}
	}
	for(int i=1;i<=k;i++){
		if(sk2[i]) sum2+=c[i];
	}
	if(sum2<sum) sum=sum2;
	cout<<sum<<endl;	

	return 0;
}

