#include<bits/stdc++.h>
using namespace std;
int f[10005],n,m,k;
long long sum;
struct node{
	long long x,y,w;
};
vector<node>v;
bool cmp(node x,node y){
	return x.w<y.w; 
}
int dfs(int x){
	if(f[x]==0)return x;
	else return dfs(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,a,b,c;i<=m;i++){
	    scanf("%d%d%d",&a,&b,&c);
	    v.push_back({a,b,c});
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(dfs(v[i].x)!=dfs(v[i].y))f[dfs(v[i].y)]=dfs(v[i].x),sum+=v[i].w;
	}
	printf("%lld",sum);
	return 0;
}
