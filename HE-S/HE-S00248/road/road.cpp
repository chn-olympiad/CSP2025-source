#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
//m<=1e6 k<=10
struct re{
	int u,v,w;
}e[N],v[N];
int n,m,k,f[N],ans,cnt,nn;
bool cmp(re x,re y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	return f[x];
}
void dfs(){
	ans=0,cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v1=find(e[i].v);
		if(u==v1)continue;
		f[u]=v1;
		ans+=e[i].w;
		cnt++;
		v[++nn].u=e[i].u;
		v[nn].v=e[i].v;
		v[nn].w=e[i].w;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	dfs();
	int cc=0;
	for(int i=1;i<=k;i++){
		int c,k;
		cin>>c;
		bool f=1;
		if(c>=ans)f=0;
		for(int j=1;j<=n;j++){
			cin>>k;
			if(c+k<ans){
				if(f)n++,f=0,cc+=c;
				nn++;
				v[nn].u=n;v[nn].v=j;v[nn].w=k;
			}
		}
	}
	int ans1=ans;m=cnt,cnt=0,ans=0;
	//cout<<nn<<'\n';
	sort(v+1,v+1+nn,cmp);
	dfs();
	cout<<min(ans1,ans+cc);
	return 0;
}
