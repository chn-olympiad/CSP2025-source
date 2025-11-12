#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m,k,cnt,fa[N];
long long a[N][N],b[N]; 
struct node{
	int x,y;
	long long v;
}e[N*500];
bool cmp(node a,node b){
	return a.v<b.v;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	memset(a,0x3f,sizeof a);
	for(int i=1,x,y,v;i<=m;i++){
		cin>>x>>y>>v;
		if(x>y) swap(x,y);
		e[++cnt]={x,y,v};
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
			for(int k=1;k<j;k++)
				a[k][j]=min(a[k][j],b[j]+b[k]+c);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(a[i][j]==a[0][0]) continue;
			e[++cnt]={i,j,a[i][j]};
		}
	sort(e+1,e+cnt+1,cmp);
	int edges=0;
	for(int i=1;i<=cnt;i++){
		int x=find(e[i].x),y=find(e[i].y);
		if(x==y) continue;
//		cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].v<<endl;
		edges++;
		ans+=e[i].v;
//		cout<<e[i].v<<endl;
		fa[x]=y;
		if(edges==n-1) break;
	}
	cout<<ans;
	return 0;
}
