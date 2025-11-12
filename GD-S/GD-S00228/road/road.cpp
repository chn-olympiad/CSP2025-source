#include <bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=3e6+20;
unsigned long long ans=1e12;
int n,m,k;
struct edge{
	int u,v;
	long long c;
	bool operator < (const edge& t)const{
		return t.c<c;
	}
};
int fa[1025][N];
int find(int st,int u){
	if(fa[st][u]==u) return u;
	else return fa[st][u]=find(st,fa[st][u]);
}


vector<edge> vec;
priority_queue<edge> q[1050];
long long c[20];
long long a[20][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	long long w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		q[1025].push({x,y,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	unsigned long long sum=0;
	int K=(1<<k)-1;
	for(int i=0;i<=K;i++){
		sum=0;
     	q[i]=q[1025];
		for(int j=1;j<=n;j++) fa[i][j]=j;
		int cur=i;
		int cnt=1;
		while(cur){
			if((cur&1)==1){
				sum+=c[cnt];
				for(int h=1;h<=n;h++){
					for(int p=h+1;p<=n;p++){
						if(h==p) continue;
						q[i].push({h,p,a[cnt][h]+a[cnt][p]});
					}
				}
			}
			cnt++;
			cur>>=1;
		}
		int ednum=0;
		while(!q[i].empty()){
			edge tp=q[i].top();
			q[i].pop();
			x=tp.u; y=tp.v;
			int xx=find(i,x);
			int yy=find(i,y);
			if(xx==yy) continue;
			fa[i][yy]=xx;
			sum+=tp.c; 
			if(sum>ans) break;
			ednum++;
			if(ednum==n) break;
		}
		if(ans>sum) ans=sum;
	}
	cout<<ans;
	
}

