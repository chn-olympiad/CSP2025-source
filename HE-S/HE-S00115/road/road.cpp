#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,val;
};
vector<node>a[10100];
int add(int u,int v,int w){
	a[u].push_back(node({v,w}));
}
int n,m,k;
struct line{
	int u,v,w;
};
line b[2000002];
int fa[10100];
int cntb=1;
int c[15];
bool viscty[15];
line ans[2000002];
bool joincity[15];
int anscnt=1;
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
bool cmp(line a,line b){
	return a.w<b.w;
}
bool cmp2(line a,line b){
	return a.u<b.u;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		
		add(u,v,w);
		add(v,u,w);
		b[cntb].u=u;
		b[cntb].v=v;
		b[cntb++].w=w;
	}
	for(int i=1;i<=k;i++){
		
		cin>>c[k];
		for(int j=1;j<=n;j++){
			int tmp;
			cin>>tmp;
			add(n+i,j,tmp);
			b[cntb].u=n+i;
			b[cntb].v=j;
			b[cntb++].w=tmp;
		}
	}
	sort(b+1,b+cntb+1,cmp);
	for(int i=1;i<=cntb;i++){
		if(find(b[i].u)!=find(b[i].v)){
			fa[find(b[i].u)]=find(b[i].v);
			ans[anscnt++]=b[i];
		}
		//if(b[i].u>n){
			
			
		//}
		
	}
	sort(ans+1,ans+anscnt+1,cmp2);
	long long sum=0;
	for(int i=1;i<=anscnt;i++){
		if(ans[i].u>n){
			bool lft=0,rht=0;
			if(i!=1&&ans[i-1].u==ans[i].u){
				lft=1;
			}
			
			if(i!=n+1&&ans[i+1].u==ans[i].u){
				//cout<<ans[i+1].u<<' '<<ans[i].u<<endl;
				rht=1;
			}
		//	cout<<lft<<rht<<endl;
			if(!lft&&!rht){
				ans[i].w=0;
				c[ans[i].u]=0;
			}
			
		}
		sum+=ans[i].w;
		
	}
	for(int i=1;i<=k;i++){
		sum+=c[i];
	}
	cout<<sum;
	return 0;
}
