#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,nn,m,c[10005],a[15][10005],fa[10005],k,ans=1e12,id[15];
struct node{
	LL w,u,v;
};
bool operator <(node p,node q){
	return p.w<q.w;
}
node e[2000005];
vector<node> ee;
LL find(LL x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
LL kruskal(){
	LL res=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(ee.begin(),ee.end());
	for(auto i : ee){
		LL x=find(i.u),y=find(i.v),z=i.w;
		if(x==y) continue;
		res+=z;
		fa[x]=y;
		cnt++;
		if(cnt==nn-1) return res;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;nn=n;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	LL num=0;
	for(int i=1;i<=k;i++){
		cin>>c[num+1];
		if(c[num+1]){
			num++;
			id[num]=i;
			for(int j=1;j<=n;j++) cin>>a[num][j];
		}else{
			n++;
			for(int j=1;j<=n;j++){
				cin>>e[++m].w;
				e[m].u=i,e[m].v=j;
			}
		}
	}
	if(!num){
		for(int i=1;i<=m;i++) ee.emplace_back(e[i]);
		cout<<kruskal();
		return 0;
	}
	for(LL s=0;s<=((1<<num)-1);s++){
		LL res=0;nn=n;
		ee.clear();
		for(int i=1;i<=num;i++){
			if(s&(1<<(i-1))){
				res+=c[i];nn++;
				for(int j=1;j<=n;j++) ee.push_back({a[i][j],id[i]+n,j});
			}
		}
		if(res>ans) continue;
		for(int i=1;i<=m;i++) ee.emplace_back(e[i]);
//		for(auto i : ee){
//			cout<<i.u<<' '<<i.v<<' '<<i.w<<"\n";
//		}
		res+=kruskal();
		//cout<<res<<"\n";
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 0 100 100 1
1 100 0 1 1

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/