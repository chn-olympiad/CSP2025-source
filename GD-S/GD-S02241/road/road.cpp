#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a,b,c,h[10004],tag[10004],g1[10004][10004];
bool g[10004][10004];
long long nm,ans,ci;
vector<long long> v[10004];
queue<long long> q;

struct node{
	long long l,r,d;
}t[20000000];


bool bfs(long long x,long long y){
	long long fa=-1;
	while(!q.empty()){
		x=q.front(),q.pop();
		fa=q.front(),q.pop();
		for(int i=0;i<v[x].size();i++){
			if(v[x][i]==fa) continue;
			if(v[x][i]==y){
				while(!q.empty()) q.pop();return 0;
			}
			q.push(v[x][i]),q.push(x);
		}
	}
	while(!q.empty()) q.pop();
	return 1;
}

void up(long long x,long long y,long long z,long long now){
	t[now].l=x,t[now].r=y,t[now].d=z;
	while(now>1){
		if(t[now].d<t[now/2].d) swap(t[now].l,t[now/2].l),swap(t[now].r,t[now/2].r),swap(t[now].d,t[now/2].d),now/=2;
		else return;
	}
}
void down(long long now){
	t[now].l=t[nm].l,t[now].r=t[nm].r,t[now].d=t[nm].d,nm--;
	while(now<=nm){
		long long y=now*2;
		if(y+1<=nm&&t[y+1].d<t[y].d) y++;
		if(y>nm) return;
		if(t[now].d>t[y].d) swap(t[now].l,t[y].l),swap(t[now].r,t[y].r),swap(t[now].d,t[y].d),now=y;
		else return;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		if(g[a][b]){
			if(g1[a][b]<=c) continue;
			else g1[a][b]=c,g1[b][a]=c;
		}else g[a][b]=1,g[b][a]=1,g1[a][b]=c,g1[b][a]=c;
	}
	for(int i=1;i<=k;i++){
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>h[j];
			for(int ii=1;ii<j;ii++){
				if(g[j][ii]){
					if(g1[j][ii]<=a+h[j]+h[ii]) continue;
					else g1[j][ii]=a+h[j]+h[ii],g1[j][ii]=a+h[j]+h[ii];
				}else g[j][ii]=1,g[ii][j]=1,g1[j][ii]=a+h[j]+h[ii],g1[ii][j]=a+h[j]+h[ii];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]){
				nm++,up(i,j,g1[i][j],nm);
			}
		}
	}
	while(nm>0){
		if(tag[t[1].l]==1&&tag[t[1].r]==1){
			q.push(t[1].l),q.push(-1);
			if(bfs(1,t[1].r)){
				v[t[1].r].push_back(t[1].l),v[t[1].l].push_back(t[1].r);
				ans+=t[1].d;
				ci++;
			}
		}else{
			if(tag[t[1].l]==0) tag[t[1].l]=1;
			if(tag[t[1].r]==0) tag[t[1].r]=1;
			v[t[1].r].push_back(t[1].l),v[t[1].l].push_back(t[1].r);
			ans+=t[1].d;
			ci++;
		}
		down(1);
		if(ci>=n-1) break;
	}
	cout<<ans;
	return 0;
}
