//GZ-S00278 毕节市七星关东辰实验学校 杨鹏鸣 
#include<bits/stdc++.h>
#define int unsigned long long 
using namespace std;
const int N=2e6,M=1e4+10;
struct node{
	int u,v,con;
}e[N];
int n,m,k,ans=0;
int c[15];
int a[15][N]; 
int fa[M];
bool cmp(node a,node b){
	return a.con<b.con;
}
int find(int x){
	if(x==fa[x]) return x;
	return find(fa[x]);
}
void join(int x,int y){
	fa[x]=y;
	return ;
}
void solve(int p){
	int sum=0;
	node s[n+m+5];
	for(int i=1;i<=m;i++){
		s[i].con=e[i].con;
		s[i].u=e[i].u;
		s[i].v=e[i].v;
	}
	for(int i=m+1;i<=m+n;i++){
		s[i].con=a[p][i-m];
		s[i].u=n+1;
		s[i].v=i-m;
	}
	sort(s+1,s+m+n+1,cmp);
	for(int i=1;i<=n+1;i++){
		fa[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=m+n;i++){
		int u1=s[i].u,v1=s[i].v;
		if(find(u1)==find(v1)){continue;}
		else{
			sum+=s[i].con;
			join(find(v1),find(u1));
			cnt++;
			if(cnt==n){
				break;
			}
		}
	}
	ans=min(ans,sum+c[p]);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].con;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n+1;i++){
		fa[i]=i;
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u1=e[i].u,v1=e[i].v;
		if(find(u1)==find(v1)){continue;}
		else{
			ans+=e[i].con;
			join(v1,u1);
			cnt++;
			if(cnt==n-1){
				break;
			}
		}
	}
	for(int i=1;i<=k;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}
