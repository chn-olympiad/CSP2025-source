#include<bits/stdc++.h>
#define int long long
#define N 10005
#define M 1000005 
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(-x);return;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
struct node{
	int to,w;
};
int n,m,k,c[15],g[15][N],dis[N],ans=1145141919810,flag[N],used[15];
vector<node>a[10015];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int solve(){
	memset(flag,0,sizeof flag);
	memset(dis,0x3f,sizeof dis);
	int sum=0;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		while(!q.empty()&&flag[q.top().second])q.pop();
		if(q.empty())break;
		int u=q.top().second;
		q.pop();
		sum+=dis[u];dis[u]=0;
		flag[u]=1;
		for(auto i:a[u]){
			if(i.w<=dis[i.to]){
				dis[i.to]=i.w;
				if(!flag[i.to])q.push({i.w,i.to});
			}
		}
	}
	return sum;
}
void dfs(int now,int lstans,int cnt){
	for(int i=1;i<=k;i++){
		if(used[i])continue;
		for(int j=1;j<=n;j++)a[i+n].push_back(node{j,g[i][j]}),a[j].push_back(node{i+n,g[i][j]});
		cnt+=c[i];
		int kl=solve()+cnt;
		ans=min(ans,kl);
		if(kl>lstans){
			a[i+n].clear();
			return;
		}
		used[i]=1;
		dfs(now+1,kl,cnt);
		used[i]=0;
		a[i+n].clear();
		for(int j=1;j<=n;j++){
			for(int p=0;p<a[j].size();p++){
				if(a[j][p].to==i+n){a[j].erase(a[j].begin()+p);break;}
			}
		}
	}
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		a[u].push_back(node{v,w});
		a[v].push_back(node{u,w});
	}
	bool flgg=false;
	for(int i=1;i<=k;i++){
		bool flg=true;
		c[i]=read();
		for(int j=1;j<=n;j++){
			g[i][j]=read();
			if(g[i][j]==0)flg=false;
		}
		if(c[i]!=0)flg=true;
		if(flg)flgg=true;
	}
	if(!flgg){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(g[i][j]==0){
					for(int l=1;l<=n;l++){
						if(j==l)continue;
						a[j].push_back(node{l,g[i][l]});
						a[l].push_back(node{j,g[i][l]});
					}
				}
			}
		}
		cout<<solve();
		return 0;
	}
	ans=solve();
	dfs(0,ans,0);
	cout<<ans;
	return 0;
}
/*
Rp++ Rp++ 
Genshin Impact
mihoyoÖúÎÒ!
*/ 
