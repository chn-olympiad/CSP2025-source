#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int L,R;
	long long Len;
};
const int N=1e4+10;
const int M=1e6+10;
Edge e[M];
Edge E[N*20];
int n,m,k;
bool cmp(Edge x,Edge y){
	return x.Len<y.Len;
}
bool operator<(Edge x,Edge y){
	return x.Len>y.Len;
}
priority_queue<Edge>pq;
int fath[N+10];
int Get_Father(int i){
	if(i==fath[i]) return i;
	else return fath[i]=Get_Father(fath[i]);
}
void Follow(int i,int j){
	i=Get_Father(i);
	j=Get_Father(j);
	if(i!=j) fath[i]=j;
}
void Clear(){
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n+k;i++) fath[i]=i;
}
long long c[20];
long long a[20][N];
long long ans;
void dfs(int x,int p,long long sum){
	if(x>k){
		if(p==n-1||sum>ans) return ;
		Clear();
		for(int i=1;i<=p;i++) pq.push(E[i]);
		for(int i=1;i<=p;i++){
			Edge p=pq.top();
			pq.pop();
			if(Get_Father(p.L)==Get_Father(p.R)) continue;
			sum+=p.Len;
			if(sum>=ans) return ;
			Follow(p.L,p.R);
		}
		ans=sum;
		return ;
	}
	dfs(x+1,p,sum);
	for(int i=1;i<=n;i++) E[p+i]={n+x,i,a[x][i]};
	dfs(x+1,p+n,sum+c[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		e[i]={a,b,d};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
	Clear();
	for(int i=1,j=1;i<=m;i++){
		if(Get_Father(e[i].L)==Get_Father(e[i].R)) continue;
		ans+=e[i].Len;
		E[j++]=e[i];
		Follow(e[i].L,e[i].R);
	}
	dfs(1,n-1,0);
	cout<<ans;
	return 0;
}
