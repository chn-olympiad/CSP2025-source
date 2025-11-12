#include<bits/stdc++.h>
#define lp long long
using namespace std;
int n,m,k,u,v;
lp w;
struct edge{
	lp dis;
	int from;
	int to;
} Bian[2000005];
int cun[15][10005];
bool cmp(const edge &a,const edge &b){
	return a.dis<b.dis;
}
int fa[10005];
int find(const int &now){
	if(fa[now]==now) return now;
	return fa[now]=find(fa[now]);
}
bool merge(const int &a,const int &b){
	int aa=find(a);
	int bb=find(b);
	if(aa!=bb){
		fa[aa]=bb;
		return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		Bian[i].from=u;
		Bian[i].to=v;
		Bian[i].dis=w;
	}
	bool xingzhiA=true;
	for(int i=1;i<=k;++i){
		cin>>cun[i][0];
		if(cun[i][0]!=0) xingzhiA=false;
		for(int j=1;j<=n;++j)
			cin>>cun[i][j];
	}
	if(xingzhiA){
		lp ans=0;
		int cnt=0,Maxcnt=n;
		int roads=m;
		int Bit=(1<<k)-1;
		for(int i=1;i<=k;++i)
			if(((Bit>>(i-1))&1)==1){
				ans+=cun[i][0];
				for(int j=1;j<=n;++j){
					Bian[roads+j].dis=cun[i][j];
					Bian[roads+j].from=i+n;
					Bian[roads+j].to=j;
				}
				roads+=n;
				++Maxcnt;
			}
		stable_sort(Bian+1,Bian+roads+1,cmp);
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		for(int i=1;i<=roads;++i){
			if(merge(Bian[i].from,Bian[i].to)){
				++cnt;
				ans+=Bian[i].dis;
			}
			if(cnt==Maxcnt-1) break;
		}
		cout<<ans;
		return 0;
	}
	lp minn=1e18;
	for(int Bit=0;Bit<(1<<k);++Bit){
		lp ans=0;
		int cnt=0,Maxcnt=n;
		int roads=m;
		for(int i=1;i<=k;++i)
			if(((Bit>>(i-1))&1)==1){
				ans+=cun[i][0];
				for(int j=1;j<=n;++j){
					Bian[roads+j].dis=cun[i][j];
					Bian[roads+j].from=i+n;
					Bian[roads+j].to=j;
				}
				roads+=n;
				++Maxcnt;
			}
		stable_sort(Bian+1,Bian+roads+1,cmp);
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		for(int i=1;i<=roads;++i){
			if(merge(Bian[i].from,Bian[i].to)){
				++cnt;
				ans+=Bian[i].dis;
			}
			if(cnt==Maxcnt-1) break;
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}
