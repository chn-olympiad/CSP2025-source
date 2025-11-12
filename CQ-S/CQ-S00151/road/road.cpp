#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+35;
int n,m,k,f[N],sop[N],cnt[N],ans[N],sum,now,is[15][N];
struct node{
	int v,w,ip;
};
struct yio{
	int u,v,w;
	bool operator < (const yio ff)const{
		return w>ff.w;
	}
};
priority_queue<yio>q;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n+15;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>sop[i+n];ans[i+n]=sop[i+n];
		for(int j=1;j<=n;j++){
			int w;
			cin>>is[i+n][j];
			q.push({i+n,j,is[i+n][j]+sop[i+n]});
		}
	}
	while(q.size()){
		int x=q.top().v,y=q.top().u,w=q.top().w;
		q.pop();
		cout<<q.size();
		//cout<<w<<"\n";
		if(find(x)!=find(y)){
			if((x>n&&sop[x]==0)||(sop[y]==0&&y>n)){
				now+=ans[x]+ans[y];
				ans[x]=ans[y]=0;
			}if(sop[x]||sop[y]){
				if(sop[x])ans[x]=w;
				if(sop[y])ans[y]=w;
			}
			now=now+w-ans[x]-ans[y];
			//cout<<x<<" "<<y<<" "<<now<<"\n";
			f[find(x)]=find(y);
			if(sop[y])swap(x,y);
			if(sop[x]){
				for(int i=1;i<=n;i++){
					q.push({x,i,is[x][i]});
				}
				sop[x]=0;
				//sort(kp.begin(),kp.end(),cmp);
			}
			
		}
	}
	cout<<now;
//	q.push({1,0,1});
//	while(q.size()){
//		int x=q.top().x,ip=q.top().ip,y=q.top().y;
//		//cout<<x<<"\n";
//		q.pop();
//		if(ip>=vis[x])continue;
//		s[x].push_back(y);
//		vis[x]=ip;
//		for(int i=0;i<a[x].size();i++){
//			if(x>n){
//				q.push({a[x][i].v,sop[x]+a[x][i].w,x});
//			}
//			else{
//				q.push({a[x][i].v,a[x][i].w,x});
//			}
//		}
//	}
//	for(int i=1;i<=n+k;i++){
//		if(i>n&&cnt[i]==0)continue;
//		int p=s[i].size();
//		if(p!=0)cnt[s[i][p-1]]++,sum-=sop[s[i][p-1]];
//	//	if(p!=0)cout<<s[i][p-1]<<"\n";
//		sum+=vis[i]+sop[i];
//		//cout<<ans[i]<<" ";
//	}
	//cout<<sum;
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
