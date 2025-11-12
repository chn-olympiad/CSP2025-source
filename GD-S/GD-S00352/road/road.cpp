#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct aa{
	long long x,y;
};

bool operator<(aa a,aa b){
	return a.x<b.x;
}

long long n,m,k,s,ss;
vector<aa>a[10010],b[10010];
long long d[10010];
bool v[10010];
int kk[11][10010];

//不会最小生成树炸了写个dijk凑合用吧 
void dijk(int p){
	priority_queue<aa>q;
	memset(d,127,sizeof(d));
	memset(v,0,sizeof(v));
	d[p]=0;q.push({0,p});v[p]=1;
	while(!q.empty()){
		int u=q.top().y;
		q.pop();
		for(int i=0;i<a[u].size();i++){
			int x=a[u][i].x,y=a[u][i].y;
			if(d[x]>d[u]+y){
				d[x]=d[u]+y;
				if(!v[x]){
					v[x]=1;
					q.push({-d[x],x});
				}
			}
		}
	}
	queue<int>f;
	f.push(p);
	while(!f.empty()){
		int g=f.front();
		f.pop();
		for(int i=0;i<a[g].size();i++){
			if(d[g]+a[g][i].y==d[a[g][i].x]){
				b[g].push_back({a[g][i].x,a[g][i].y});
				b[a[g][i].x].push_back({g,a[g][i].y});
				s+=a[g][i].y;
				f.push(a[g][i].x);
			}
		}
	}
}

void dfs(int g,int ll,int h){
	for(int i=0;i<b[g].size();i++){
		int x=b[g][i].x,y=b[g][i].y;
		if(x==ll)continue;
		if(y>kk[h][x]){
			ss-=y-kk[h][x];
			b[g][i].y=kk[h][x];
			dfs(x,g,h);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//关流也不会呜呜呜 
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	dijk(1);
	if(k==0){
		cout<<s;return 0;
	}
	int mk=0;
	for(int i=1;i<=k;i++){
		cin>>kk[i][0];mk=max(mk,kk[i][0]);
		for(int j=1;j<=n;j++){
			cin>>kk[i][j];mk=max(mk,kk[i][j]);
		}
	}
	if(mk==0){
		cout<<0;return 0;
	}
	for(int i=1;i<=k;i++){
//		cout<<s<<endl;
		ss=s+kk[i][0];int bb=1;
		for(int j=1;j<=n;j++){
			for(int l=0;l<b[j].size();l++){
				if(b[j][l].y>kk[i][j]+kk[i][l]){
					bb=0;ss-=b[j][l].y-kk[i][j]-kk[i][l];
					b[j][l].y=kk[i][j]+kk[i][l];
					dfs(j,l,i);
					dfs(l,j,i);
				}
			}
		}
		if(b==0)s=ss;
	}
	cout<<s;
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
