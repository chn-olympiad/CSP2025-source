#include<bits/stdc++.h>
using namespace std;
#define N 1000100
#define int long long
struct node {
	int u,v,w;
};
int n,m,k,fl[10000][10000],dao=1,fla[N],ans=1e9,tmp;
vector<node> e[N];
void dfs(int s) {
	if(dao==n) {
		ans=min(ans,tmp);
		return;
	}
	for(auto i:e[s]) {
		if(fl[i.u][i.v]>=2) {
			continue;
		}
		if(fla[i.v]==0) dao++;
		if(fl[i.u][i.v]==0) {
			tmp+=i.w;
			fla[i.v]++;
			fla[i.u]++;
		}
		fl[i.u][i.v]+=1;
		fl[i.v][i.u]+=1;
		dfs(i.v);
		fl[i.u][i.v]-=1;
		fl[i.v][i.u]-=1;
		if(fl[i.u][i.v]==0) {
			fla[i.v]--;
			fla[i.u]--;
			tmp-=i.w;
		}
		if(fla[i.v]==0) dao--;
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	k=0;//无能狂怒
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back(node {x,y,z});
		e[y].push_back(node {y,x,z});
	}
	for(int i=1; i<=k; i++) {
		cout<<"出 点 简 单 题 会 活 吗 ？ ？ ？";
		cout<<"别 给 我 禁 赛 了 ! ! ! ! ! ! ! ";
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
4 4 100000
1 4 6
2 3 7
4 2 5
4 3 4
*/
