#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,x,y,z,cnt,fa[100005],num,c[11],gx[11];
ll ans=1e16;
int ex[11][10004];
bool ok[11],in[11];
struct Edge{
	int x,y,val;
	bool operator < (const Edge &y)const{
		return val<y.val;
	}
}e[1200006],now[12000006];
inline int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
inline void dfs(int u){
	if(u==k+1){
		ll ret=0;
//		now.clear();
		for(int i=1;i<=m;i++)now[i]=e[i];
		cnt=m;
		for(int i=1;i<=k;i++){
			if(in[i]){
				num++;
				ret+=c[i];
				for(int j=1;j<=n;j++){
//					cnt++;
//					Edge ins={j,n+i,ex[i][j]};
//					now.insert(upper_bound(now.begin(),now.end(),ins),ins);
					now[++cnt]={j,n+i,ex[i][j]};
				}
			}
		} 
		sort(now+1,now+cnt+1);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		num+=n-1;
		for(int i=1;i<=cnt;i++){
			x=now[i].x,y=now[i].y,z=now[i].val;
			if(find(x)!=find(y)){
				fa[find(x)]=find(y);
				ret+=1ll*z;
				num--;
				if(num==0)break;
			}
		}
		ans=min(ans,ret);
		return ;
	}
	if(!ok[u])dfs(u+1);
	in[u]=1;
	dfs(u+1);
	in[u]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ok[i]=1;
		if(c[i])ok[i]=0;
		bool flag=0;
		for(int j=1;j<=n;j++){
			cin>>ex[i][j];
			if(ex[i][j]==0)flag=1;
		}
		if(flag&&ok[i])ok[i]=1;
	}
	sort(e+1,e+m+1);
	dfs(1);
	cout<<ans;
	return 0;
} 
/*
2 1 1
1 2 4
2 3 9

5 4 1
1 2 1 
1 5 1
2 3 1
2 4 1
100 1 1 1 1 1
*/
