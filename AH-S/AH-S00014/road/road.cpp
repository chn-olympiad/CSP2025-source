#include<bits/stdc++.h>
using namespace std;

int n,m,k;

struct edge{
	int u,v,w;
};

int len;

edge e[1050001];

int u,v,w;

int arr[11][11660];

int father[111166];

long long minn=0x3f3f3f3f3f3f3f3f;

long long ans=0;

bool cmp(edge x,edge y){
	return x.w<y.w;
}

void init(){
	for(int i=1;i<=n+k;i++){
		father[i]=i;
	}
	return;
}

int getl(int x){
	if(father[x]!=x){
		father[x]=getl(father[x]);
	}
	return father[x];
}

int vi[1111660];

edge a[1111660];

void ks(int p){
	ans=0;
	init();
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		u=getl(a[i].u);
		v=getl(a[i].v);
		if(u!=v){
			ans=ans+a[i].w;
			father[u]=v;
		}
	}
	minn=min(minn,ans+p);
	return;
}

void dfs(int ndx,int now){
	if(ndx==k+1){
		for(int i=0;i<len;i++){
			a[i]=e[i];
		}
		ks(now);
		return;
	}
	if(vi[ndx]!=0){
		dfs(ndx+1,now);
	}
	for(int i=1;i<=n;i++){
		e[len]={i,n+ndx,arr[ndx][i]};
		len++;
	}
	dfs(ndx+1,now+vi[ndx]);
	len-=n;
	return;
}

bool especial=true;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	len=m;
	for(int i=1;i<=k;i++){
		cin>>vi[i];
		if(vi[i]!=0){
			especial=false;
		}
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
		}
	}
	dfs(1,0);
	cout<<minn;
	return 0;
}
