#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
struct edge{
	int u,v,w;
}b[12][10020];
vector<edge>e[12];
int n,m,k,ans,f[10020],c[12],s,cs;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void dfs(int x){
	if(x==k+1){
		return;
	}
	for(int i=0;i<e[x].size();i++){
		e[x+1][i]=e[x][i];
	}
	dfs(x+1);
	s++;
	cs+=c[x];
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	int cnt=0,sum=0,j=1;
	for(int i=0;i<s;i++){
		if(cnt==s-1)break;
		while(j<=n&&b[x][j].w<e[x][i].w){
			int ru=find(b[x][j].u),rv=find(b[x][j].v);
			if(ru!=rv){
				f[rv]=ru;
				sum+=b[x][j].w;
				e[x+1][cnt]=b[x][j];
				cnt++;
			}
			j++;
			if(cnt==s-1)break;
		}
		if(cnt==s-1)break;
		int ru=find(e[x][i].u),rv=find(e[x][i].v);
		if(ru!=rv){
			f[rv]=ru;
			sum+=e[x][i].w;
			e[x+1][cnt]=e[x][i];
			cnt++;
		}
	}
	ans=min(ans,sum+cs);
	dfs(x+1);
	s--;
	cs-=c[x];
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	e[0].resize(m+1);
	for(int i=0;i<m;i++){
		int u=read(),v=read(),w=read();
		e[0][i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			b[i][j].w=read();
			b[i][j].u=i+n;
			b[i][j].v=j;
		}
		sort(b[i]+1,b[i]+n+1,cmp);
	}
	for(int i=1;i<=k+1;i++){
		e[i].resize(k+n+1);
	}
	sort(e[0].begin(),e[0].end(),cmp);
	s=n;
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=0;i<e[0].size();i++){
		int ru=find(e[0][i].u),rv=find(e[0][i].v);
		if(ru!=rv){
			f[rv]=ru;
			sum+=e[0][i].w;
			e[1][cnt]=e[0][i];
			cnt++;
		}
		if(cnt==s-1)break;
	}
	ans=sum;
	dfs(1);
	cout<<ans;
	return 0;
}
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
