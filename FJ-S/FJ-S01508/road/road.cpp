#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5;
int n,m,k;
struct edge{
	int u,v,w;
};
vector <edge> e;
int c[MAXN],a[15][MAXN];
int fa[MAXN+20];
int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void unionset(int x,int y){
	x=find(x),y=find(y);
	if (x==y) return;
	fa[x]=y;
}
bool cmp(edge x,edge y){return x.w<y.w;}
int sp_A=0,sp_A2=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back((edge){u,v,w});
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		if (c[i]==0) sp_A++;
		bool flag=false;
		for (int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			if (a[i][j]==0) flag=true;
		}
		if (flag) sp_A2++;
	}
	if (k==0 || (sp_A==k && sp_A2==k)){
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++){
				e.push_back((edge){n+i,j,a[i][j]});
			}
		}
		for (int i=1;i<=n+k;i++) fa[i]=i;
		sort(e.begin(),e.end(),cmp);
		int ans=0;
		int cnt=0,i=0;
		while (cnt<n+k-1){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if (find(u)!=find(v)){
				unionset(u,v);
				ans+=w;
				cnt++;
//				cout<<u<<" "<<v<<endl;
			}
			i++;
		}
		cout<<ans;
	}
	
	return 0;
}
// rp++;

