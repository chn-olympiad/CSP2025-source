#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c[20],num,fat,fb,pd[20],flag,zjz,ansz=1e18;
struct Node{
	ll sy;
	ll u,v,w;
}e[1100010];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
ll fa[200010];
ll find(ll u){
	if(u!=fa[u]) return fa[u]=find(fa[u]);
	return u;
}
ll bm(){
	ll ans=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=num;i++){
		if(pd[e[i].sy]==0){
			continue;
		}
		fat=find(e[i].v),fb=find(e[i].u);
		if(fat!=fb){
			fa[fat]=fb;
			ans+=e[i].w;
		}
	}
	return ans;
}
void dfs(ll dep){
	if(dep==k){
		ansz=min(ansz,bm()+zjz);
		return ;
	}
	dfs(dep+1);
	pd[dep+1]=1;
	zjz+=c[dep+1];
	dfs(dep+1);
	pd[dep+1]=0;
	zjz-=c[dep+1];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].sy=0;
	}
	num=m;
	for(int i=1;i<=k;i++){
		ll cnt=0;
		cin>>c[i];
		cnt+=c[i];
		for(int j=1;j<=n;j++){
			++num;
			cin>>e[num].w;
			cnt+=e[num].w;
			e[num].u=n+i;
			e[num].v=j;
			e[num].sy=i; 
		}
		if(cnt==0){
			flag=1;
		}
	}
	sort(e+1,e+num+1,cmp);
	if(flag==1){
		cout<<"0";
		return 0;
	}
	pd[0]=1;
	if(k==0){
		cout<<bm();
		return 0;
	}
	dfs(0);
	cout<<ansz;
} 


