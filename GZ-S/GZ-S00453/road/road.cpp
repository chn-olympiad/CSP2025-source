//GZ-S00453 毕节梁才学校 阮松海 
#include<bits/stdc++.h> 
using namespace std;

int n,m,k;
int to[2000010];
int nt[2000010];
int idx;
int h[10010];
int d[10010];
int w[2000010];
typedef long long LL;
LL ans;
void add(int x,int y,int z){
	to[idx]=y;
	w[idx]=z;
	nt[idx]=h[x];
	h[x]=idx;
	idx++;
}
//typedef pair<int,int> PII;
struct oq{
	int x,y;
};
typedef pair<int,oq> PII

priority_queue<PII,vector<PII>,greater<PII> > p;

map<int,bool> v[10010];

void du(){
	while(p.size()>0){
		 q=p.top();
		p.pop();
		oq o=q.second;
		int z=q.first;
		int x=o.x ;
		int y=o.y;
		if(!v[x][y]){
			v[x][y]=true;
			v[y][x]=true;
			ans+=z;
		}
	}
}



int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		p.push((PII){z,x,y});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int x;
			scanf("%d",&x);
		}
	}
	du();
	printf("%d",ans);
	
	
	
	
	return 0;
}
