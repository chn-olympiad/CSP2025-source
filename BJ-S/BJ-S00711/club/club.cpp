#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e5+10;
set<int> e[4];
int n,a[maxn][4];
int to[maxn][4],it[maxn];
int cur;
int m,id[maxn];
inline bool cmp1(int x,int y){
	return a[cur][x]>a[cur][y];
}
inline bool cmp2(int x,int y){
	return a[x][to[x][1]]-a[x][to[x][2]]<a[y][to[y][1]]-a[y][to[y][2]];
}
inline void so(int x){
	for(int i:e[x]) id[++m]=i;
	sort(id+1,id+1+m,cmp2);
	for(int i=1;i<=m-n/2;i++){
		e[x].erase(id[i]);
		it[id[i]]++;
		e[to[id[i]][it[id[i]]]].insert(id[i]);
	}
}
inline void sol(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j],to[i][j]=j;
		cur=i;
		sort(to[i]+1,to[i]+4,cmp1);
		e[to[i][1]].insert(i);
		it[i]=1;
	}
	for(int i=1;i<=3;i++)
		if(e[i].size()>n/2){so(i);break;}
	ll ans=0;
	for(int i=1;i<=3;i++)
		for(int x:e[i]) ans+=a[x][i];
	cout<<ans<<endl;
	for(int i=1;i<=3;i++) e[i].clear();
	m=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) sol();
	return 0;
}
