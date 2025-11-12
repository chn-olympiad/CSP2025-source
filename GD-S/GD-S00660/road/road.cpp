#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,M=1e6+1,K=11;
struct edge{
	int fr,to,we,fl;
}e[1008611];
int n,m,k,cnt,c[K],a[K][N],fa[N+K],sum,b[K];
bool cmp(edge a,edge b){
	return a.we<b.we;
}
int find(int x){
	if(x!=fa[x]){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
bool che(){
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1)){
			return 0;
		}
	}
	return 1;
}
int kr(){
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(find(e[i].fr)!=find(e[i].to)){
			fa[find(e[i].fr)]=find(e[i].to);
			sum++;
			if(e[i].fl){
				b[e[i].fr]=1;
			}
			ans+=e[i].we;
			if(sum>=n-1&&che()){
				return ans;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>e[i].fr>>e[i].to>>e[i].we;
		e[i].fl=0;
		cnt++;
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		fa[i]=i;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++cnt]={n+i,j,a[i][j],1};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int temp=0;
	for(int i=1;i<=k;i++){
		if(b[i]){
			temp+=c[i];
		}
	}
	cout<<kr()+temp;
	return 0;
}//witten by zsz0804_/GD-S00660

