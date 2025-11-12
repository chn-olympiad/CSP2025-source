#include <bits/stdc++.h>
#include <map>
#include <set>
using namespace std;
int f[10010];
int Find(int x){
	if (f[x]==x){
		return x;
	}
	return f[x]=Find(f[x]);
}
int n,m,k;
long long c[20],a[10010][10010];
set<pair<long long,pair<int,int>>> s;
void solve1(){
	long long ans=0,cnt=0;
	for (auto i:s){
		long long w=i.first,u=i.second.first,v=i.second.second;
		if (Find(u)!=Find(v)){
			f[Find(u)]=Find(v);
			ans+=w;
			cnt++;
		}
		if (cnt==n-1){
			break;
		}
	}
	printf("%lld",ans);
}
map<pair<int,int>,long long> mapp;
void solve2(){
	for (int p=1;p<=k;p++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				mapp[{i,j}]=min(mapp[{i,j}],c[p]+a[p][i]+a[p][j]);
				if (n>100&&p==k){
					s.insert({mapp[{i,j}],{i,j}});
				}
			}
		}
	}
	if (n<=100){
		for (int p=1;p<=n;p++){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					mapp[{i,j}]=min(mapp[{i,j}],mapp[{i,k}]+mapp[{k,j}]);
					if (p==k){
						s.insert({mapp[{i,j}],{i,j}});
					}
				}
			}
		}
	}
	long long ans=0,cnt=0;
	for (auto i:s){
		long long w=i.first,u=i.second.first,v=i.second.second;
		if (Find(u)!=Find(v)){
			f[Find(u)]=Find(v);
			ans+=w;
			cnt++;
		}
		if (cnt==n-1){
			break;
		}
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		f[i]=i;
		for (int j=1;j<=n;j++){
			mapp[{i,j}]=0x3f3f3f3f;
		}
	}
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mapp[{u,v}]=w;
		mapp[{v,u}]=w;
		if (!k){
			s.insert({w,{u,v}});
		}
	}
	for (int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if (!k){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
