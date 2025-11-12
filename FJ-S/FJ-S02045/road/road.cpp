#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
long long ans=LLONG_MAX;
struct Node{
	long long u,v,w;
}e[M];
struct Town{
	long long c,a[N];
}t[15];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return find(fa[x]);
}
void dfs(int len,long long cnt,int sum){
	if(len>=k+m)return;
	if(cnt>=ans)return;
	if(sum==n-1){
		int q=find(1);
		for(int i=2;i<=n;i++)
			if(find(i)!=q)return;
		ans=cnt;
	}
	if(len<m){
		for(int i=len+1;i<=n;i++){
			int nx=find(e[i].u),ny=find(e[i].v);
			if(nx==ny)continue;
			fa[ny]=nx;
			dfs(i,cnt+e[i].w,sum+1);
			fa[ny]=ny;
		}
	}
	else{
		for(int i=len-m+1;i<=k;i++){
			for(int j=1;j<=n;j++){
				int nx=find(j);
				for(int p=j+1;p<=n;p++){
					int ny=find(p);
					if(nx==ny)continue;
					fa[ny]=nx;
					dfs(i+m,cnt+t[i].c+t[i].a[j]+t[i].a[p],sum+1);
					fa[ny]=ny;
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>t[i].c;
		if(t[i].c)flag=0;
		for(int j=1;j<=n;j++){
			cin>>t[i].a[j];
			if(t[i].a[j])flag=0;
		}	
	}
	if(flag){
		cout<<0;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
