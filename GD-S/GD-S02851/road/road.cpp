#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,m,k,fa[N],ans,c[15],a[15][10005];
struct node{
	int a,b,w,f;
}e[N],ne[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)fa[i]=i;
	for(int i = 1;i<=m;i++)cin>>e[i].a>>e[i].b>>e[i].w;
	sort(e+1,e+m+1,cmp);
	for(int i = 1;i<=m;i++){
		int a=find(e[i].a),b=find(e[i].b);
		if(a!=b){
			fa[a]=b;
			ans+=e[i].w;
			e[i].f=1;
		}  
	}
	if(!k){
		cout<<ans<<'\n';
		return 0;
	}
	//cout<<ans<<'\n';
	for(int i = 1;i<=n+k;i++)fa[i]=i;
	int flag=1;
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		if(c[i])flag=0;
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(flag){
		for(int i =1;i<=k;i++){
			for(int j = 1;j<=n;j++){
				e[++m]={j,i+n,a[i][j]};
			}
		}
		sort(e+1,e+m+1,cmp);
		int ans2=0;
		for(int i = 1;i<=m;i++){
			int a=find(e[i].a),b=find(e[i].b);
			if(a!=b){
				fa[a]=b;
				ans2+=e[i].w;
			}
		}
		cout<<min(ans,ans2);
		return 0;
	}
	int cnt=0;
	for(int i = 1;i<=m;i++){
		if(e[i].f)e[++cnt]={e[i].a,e[i].b,e[i].w};
	}
	for(int i =0;i<1<<k;i++){
		
		for(int i = 1;i<=cnt;i++)ne[i]={e[i].a,e[i].b,e[i].w};
		int ans2=0,idx=cnt;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j = 1;j<=k;j++){
			if(((i>>(j-1))&1)==1){
			//	cout<<"SSS"<<j; 
				ans2+=c[j];
				for(int q=1;q<=n;q++){
					ne[++idx]={j+n,q,a[j][q]};
					//cout<<j+n<<' '<<q<<'\n';
				}
			}
		}
	//	if(i==16)for(int x = 1;x<=idx;x++)cout<<ne[x].a<<' '<<ne[x].b<<' '<<ne[x].w<<'\n';
		sort(ne+1,ne+idx+1,cmp);
		
		for(int x = 1;x<=idx;x++){
			int a=find(ne[x].a),b=find(ne[x].b);
			//cout<<ne[x].a<<' '<<a<<' '<<b<<' ';
			if(a!=b){
				fa[a]=b;
				ans2+=ne[x].w;
			//	if(i==16){
				//	cout<<ne[x].a<<' '<<ne[x].b<<' '<<ne[x].w<<'\n';
			//	}
			}
		}
		//cout<<ans2<<'\n';
		ans=min(ans,ans2);
	}
	cout<<ans;
	return 0;
}
