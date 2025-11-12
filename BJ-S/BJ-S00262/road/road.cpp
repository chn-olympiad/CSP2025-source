#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,P=1e6+2;
int n,m,k;
struct node{
	int u,v;
	long long w;
}b[P];
long long c[15],a[15][N];
priority_queue<pair<long long,int> > q;
int fa[N],sz[N];
long long hsx=1e18;

int FindR(int x){
	if(fa[x]==x) return x;
	return fa[x]=FindR(fa[x]);
}
void Insert(int x,int y){
	int fx=FindR(x);
	int fy=FindR(y);
	if(fx<fy){
		fa[fy]=fx;
		sz[fx]+=sz[fy];
	}else{
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	}
}

void Dfs(int cur,int s){
	if(cur>k){
		//cout<<cur<<" "<<s<<endl;
		int cnt=n;
		long long ans=0;
		priority_queue<pair<long long,int> > qq;
		//cout<<"bug10"<<endl;
		if(s%2==1){
			ans+=c[1];
			cnt++;
			for(int i=1;i<=n;i++){
				qq.push(make_pair(-a[1][i],m+i));
			}
		}
		if(s%4>=2){
			ans+=c[2];
			cnt++;
			for(int i=1;i<=n;i++){
				qq.push(make_pair(-a[2][i],m+n+i));
			}
		}
		if(s%8>=4){
			ans+=c[3];
			cnt++;
			for(int i=1;i<=n;i++){
				qq.push(make_pair(-a[3][i],m+2*n+i));
			}
		}
		if(s%16>=8){
			ans+=c[4];
			cnt++;
			for(int i=1;i<=n;i++){
				qq.push(make_pair(-a[4][i],m+3*n+i));
			}
		}
		if(s>=16){
			ans+=c[5];
			cnt++;
			for(int i=1;i<=n;i++){
				qq.push(make_pair(-a[5][i],m+4*n+i));
			}
		}
		for(int i=1;i<=m;i++){
			qq.push(make_pair(-b[i].w,i));
		}
		//cout<<qq.size()<<endl;
		//cout<<"bug11"<<endl;

		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			sz[i]=1;
		}
		while(!qq.empty() && sz[1]<cnt){
			int id=qq.top().second;
			qq.pop();
			int fx=FindR(b[id].u),fy=FindR(b[id].v);
			if(fx==fy) continue;
			Insert(fx,fy);
			ans+=b[id].w;
			//cout<<fa[b[id].u]<<endl;
			//cout<<FindR(b[id].v)<<endl;
		}
		hsx=min(hsx,ans);
		//cout<<"bug12"<<endl;
		return ;
	}
	Dfs(cur+1,s);
	Dfs(cur+1,s+(1<<(cur-1)));
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		b[i].u=u;
		b[i].v=v;
		b[i].w=w;
		q.push(make_pair(-w,i));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[m+(i-1)*n+j].u=n+i;
			b[m+(i-1)*n+j].v=j;
			b[m+(i-1)*n+j].w=a[i][j];
		}
	}
	Dfs(1,0);
	cout<<hsx;
	return 0;
}
