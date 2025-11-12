#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
long long ans=0;
int s[100010];
int cnt=0;
struct edge{
	int u,v;
	long long w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int findd(int x){
	if(x==s[x]){
		return x;
	}
	return s[x]=findd(s[x]);
}
int main(){
	//cj=0
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	edge ed[100010];
	for(int i=1;i<=n;i++){
		s[i]=i;
	}
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>ed[cnt].u>>ed[cnt].v>>ed[cnt].w;
		cnt++;
		ed[cnt].u=ed[cnt-1].v;
		ed[cnt].v=ed[cnt-1].u;
		ed[cnt].w=ed[cnt-1].w;
	}
	sort(ed+1,ed+m+1,cmp);
	if(k==0){
		for(int i=1;i<=cnt;i++){
			int u,v;
			u=ed[i].u;
			v=ed[i].v;
			if(findd(s[u])==findd(s[v])){
				continue;
			}else{
				s[u]=findd(s[v]);
				ans+=ed[i].w;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	int c;
	for(int i=1;i<=k;i++){
		cin>>c;
		if(c==0){
			cout<<0<<endl;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
