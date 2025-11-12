#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int u[N],v[N],w[N];
int n,m,k;
int re[N];
int cnt;
int z[N];
int wei[13][N];
struct node{
	int u,v,w;
	bool operator<(const node &x)const{
	        return w>x.w;
	}
}ro[N];
//priority_queue<node>q;
bool cmp(node a,node b){
	return a.w<b.w;
}
vector<int>g[N];
int find(int x){
	if(z[x]==x)return x;
	z[x]=find(z[x]);
	return z[x];
}
void merg(int x,int y){
	z[find(x)]=find(y);
	return;
}
int krus(){//直接生成 
	int ans=0;
//	while(!q.empty()){
//		if(find(q.top().u)==find(q.top().v)){
//			q.pop();
//			continue;
//		}
//		merg(q.top().u,q.top().v);
//		ans+=q.top().w;
//		q.pop();
//	}
    sort(ro+1,ro+1+m+cnt,cmp);
    for(int i=1;i<=m+cnt;i++){
    	if(find(ro[i].u)==find(ro[i].v))continue;
    	merg(ro[i].u,ro[i].v);
    	ans+=ro[i].w;
	}
	return ans;
}
void add(int fr,int tar){//重新添加 
    //cnt=0;
//	while(!q.empty()){
//		q.pop();
//	}
//	for(int i=1;i<=m;i++){
//		q.push({u[i],v[i],w[i]});
//	}
    //每次添加时二分? 
	//for(int i=fr;i<=tar;i++){//以i为中转点 
		for(int k=1;k<=n;k++){
			for(int j=k+1;j<=n;j++){
			//	q.push({k,j,wei[i][k]+wei[i][j]});
			    ++cnt;
				ro[n+cnt]={j,k,wei[tar][k]+wei[tar][j]};
                //can[j][k]=can[k][j]=wei[tar][k]+wei[tar][j];
				//cout<<wei[i][k]<<' '<<wei[i][j]<<" lll ";
				//cout<<i<<' '<<j<<' '<<k<<' '<<wei[i][k]+wei[i][j]<<'\n';
			}
		}
//	}
}
int minn=1e10; 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//分成图 最小生成树 
	//要下去就要钱 
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+10;i++){
		z[i]=i;
	}
	for(int i=1;i<=m;i++){
//		cin>>u[i]>>v[i]>>w[i];
//		q.push({u[i],v[i],w[i]});
		cin>>ro[i].u>>ro[i].v>>ro[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>re[i];//修复价格
		for(int j=1;j<=n;j++){
			cin>>wei[i][j];//道路价格 
			//cout<<i<<' '<<j<<' '<<wei[i][j]<<'\n';
		} 
	}
	minn=krus();
	//每次kurskal O(mlog m)*100 
	for(int i=1;i<=k;i++){//枚举每个添加点，进行最小生成树 
		int now=0;
		for(int p=1;p<=n+k+10;p++){
		    z[p]=p;
	    }
	    cnt=0;
		for(int j=i;j<=k;j++){
			now+=re[j];
			add(i,j);
			//if(i==1&&j==1)cout<<"jnishjuhue"<<krus()+now<<'\n';
			minn=min(krus()+now,minn);
		}
	}
	
	cout<<minn;
	return 0;
}
