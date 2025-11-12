#include<bits/stdc++.h>
using namespace std;
#define pi pair
#define fir first
#define sec second
int n,m,k;
const int N=1e4+55,M=1e7+5;
int fa[N];
pi<int,pi<int,int> >dis[M];
int c[N];
vector<int> G[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
long long ans;
void krusual(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(dis+1,dis+1+m);
	for(int i=1;i<=m;i++){
		if(find(dis[i].sec.fir)!=find(dis[i].sec.sec)){
			fa[find(dis[i].sec.fir)]=find(dis[i].sec.sec);
			ans+=dis[i].fir;
		}
	}
	cout<<ans;
	return ;
}
void hrusual(int cnt){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	
	sort(dis+1,dis+1+cnt);
	for(int i=1;i<=m;i++){
		if(find(dis[i].sec.fir)!=find(dis[i].sec.sec)){
			if(dis[i].sec.fir>1e4||dis[i].sec.sec>1e4){
				int tmp=max(dis[i].sec.fir,dis[i].sec.sec);
				bool ck=0;
				for(auto v:G[tmp]){
					if(find(v)!=find(min(dis[i].sec.fir,dis[i].sec.sec))){
						ck=1;
						fa[find(v)]=find(min(dis[i].sec.fir,dis[i].sec.sec));
						break;
					}
				}
//				for(int j=1;j<=n;j++){
//					if(find(j)==find(tmp)&&find(j)!=find(min(dis[i].sec.fir,dis[i].sec.sec))){
//						fa[find(j)]=find(min(dis[i].sec.fir,dis[i].sec.sec));
//						ck=1;
////						break;
//					}
//				}
				if(ck){
					ans+=dis[i].fir;
				}
			}
			else{
				fa[find(dis[i].sec.fir)]=find(dis[i].sec.sec);
				ans+=dis[i].fir;
			}
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>dis[i].sec.fir>>dis[i].sec.sec>>dis[i].fir;
	}
	if(k==0){
		krusual();
		return 0;
	}
	else{
		int cnt=m;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				int kp;
				cin>>kp;
				if(kp==0){
					G[i+10000].push_back(j);
				}
				else{
					dis[++cnt].fir=kp,dis[cnt].sec.fir=i+10000,dis[cnt].sec.sec=j;
				}
			}
		}
		hrusual(cnt);
	}
}
/*
5 7 0
1 2 5
1 4 4
2 4 7
1 5 8
4 5 3
3 4 2
3 5 9

*/
