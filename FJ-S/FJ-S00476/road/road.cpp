#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,c[15];
long long a[15][N];
struct E{
	int u,v;
	long long w;
};
vector<E> e;
vector<E> x;
int fa[N+10];
long long ans=LLONG_MAX;
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
bool cmp(E a,E b){
	return a.w<b.w;
}
long long scs(int n){
//	cout<<n<<"---\n";
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	x=e;
	sort(x.begin(),x.end(),cmp);
	int cnt=0;
	long long ans=0;
	for(E i:x){
		if(cnt==n-1)break;
		int u=i.u,v=i.v;
		u=find(u),v=find(v);
		if(u!=v){
			fa[u]=v;
			cnt++;
			ans+=i.w;
		}
	}
//	cout<<ans<<endl;
	return ans;
}
void dfs(int x,int sum,int num){
	if(x>k){
		ans=min(ans,scs(n+sum)+num);
//		cout<<ans<<endl;
		return;
	}
	dfs(x+1,sum,num);
	for(int i=1;i<=n;i++){
		e.push_back({i,x+n,a[x][i]});
	}
	dfs(x+1,sum+1,num+c[x]);
	for(int i=1;i<=n;i++){
		e.pop_back();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool ts=1;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)ts=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)ts=0;
		}
	}
	if(ts){
		cout<<0;
		return 0;
	}
//	cout<<"skljsdjkf\n";
	dfs(1,0,0);
	cout<<ans;
}

