#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,k;
int c,a;
int ver[N],tot,Next[N],head[N];
long long edge[N],d[N],ans;
bool b[N];
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
void dij(){
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=n*10;i++){
		d[i]=1e18;
	}
	b[1]=0;
	d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(b[x])continue;
		b[x]=1;
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];long long z=edge[i];
			if(d[x]+z<d[y]){
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		/*add(x,y,z);
		add(y,x,z);*/
		for(int j=1;j<=k;j++){
			add(x+(j-1)*n,y+(j-1)*n,z);
			add(y+(j-1)*n,x+(j-1)*n,z);
		}
	}
	bool f=0;
	for(int i=1;i<=k;i++){
		cin>>c;
		if(c)f=1;
		for(int j=1;j<=n;j++){
			add((i-1)*n+j,i*n+j,c);
			add(i*n+j,(i-1)*n+j,c);
		}
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a)f=1;
			add(i*n+j,j,a);
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	dij();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)
		ans=max(ans,d[j+(i-1)*n]);
	}
	cout<<ans;
	return 0;
}
