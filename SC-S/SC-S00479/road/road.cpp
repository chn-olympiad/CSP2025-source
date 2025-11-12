#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,cnt,cnt2,f[10015];
bool vis[10015];
ll ans=1e18,c[15],a[15][10005];
struct node{
	int u,v;
	ll w;
	int id;
	bool operator <(const node x)const{
		return x.w<w;
	}
}e[1000005],e2[10005];
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
void solve(int s){
	priority_queue<node>q;
	int N=n-1;
	for(int i=1;i<=n+k;i++){
		vis[i]=0;
		f[i]=i;
	}
	ll sum=0;
	for(int i=1;i<=k;i++){
		if((s>>(i-1))&1){
			N++;
			sum+=c[i];
			for(int j=1;j<=n;j++){
				q.push((node){i+n,j,a[i][j]});
			}
		}
	}
	for(int i=1;i<n;i++){
		q.push(e2[i]);
	}
	node x;
	int fu,fv;
	while(!q.empty()&&N){
		x=q.top();
		q.pop();
		fu=find(x.u),fv=find(x.v);
		if(fu!=fv){
			f[fu]=fv;
			sum+=x.w;
			N--;
		}
		if(sum>=ans){
			return;
		}
	}
	ans=min(ans,sum);
}
char s;
int y;
int read(){
	y=0;
	while(s=getchar()){
		if(s<'0'||s>'9'){
			break;
		}
		y=y*10+s-'0';
	}
	return y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	priority_queue<node>q;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].id=i;
		q.push(e[i]);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int fu,fv,N=n-1;
	node x;
	while(!q.empty()&&N){
		x=q.top();
		q.pop();
		fu=find(x.u),fv=find(x.v);
		if(fu!=fv){
			f[fu]=fv;
			e2[++cnt2]=e[x.id];
			N--;
		}
	}
	for(int i=0;i<(1<<k);i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}