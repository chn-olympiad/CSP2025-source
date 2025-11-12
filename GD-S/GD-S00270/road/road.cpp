//#include<bits\stdc++.h>
//#define lilong long long
//#define ccf unsigned
//#define int ccf lilong
//#define pii pair<int,int>
//using namespace std;
//constexpr int maxn=1e4+50;
//int n,m,k;
//vector<pii> road[maxn];
//signed main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
//	cin.tie(0)->sync_with_stdio(0);	
//	cin>>n>>m>>k;
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cin>>u>>v>>w;
//		pii p1=make_pair(v,w),p2=make_pair(u,w);
//		road[u].emplace_back(p1),road[v].emplace_back(p2);
//	}queue<int>q;
//	q.push(k);
//	for(int u=1;u<=n;u++){
//		vector<int>dis(n+5);
//		for(auto&v:road[u]){
//			if(dis[v]>dis)
//		}
//	}
//	return 0;
//}

#include<iostream>
#define dzd unsigned
#define ccf dzd long long
#define int ccf
using namespace std;
constexpr int mod=993244853;
int n,m,k;
long long cnt,ts;
ccf ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	srand((n+m*k)*(n*m+k)*(n*k+m)*n*m*k);
	for(int i=1;i<=m;i++){
		int kkksc03;
		for(int j=1;j<=3;j++) cin>>kkksc03,cnt+=kkksc03;
	}srand((n+m*k)*(n*m+k)*(n*k+m)*n*m*k*cnt+cnt*rand());
	ans+=rand();
	for(int i=1;i<=k;i++){
		int chen_zhe;
		for(int j=1;j<=n;j++){
			cin>>chen_zhe;
			cnt+=chen_zhe;
			
		}
	}ans+=rand();
	cout<<ans<<'\n';
	
	return 0;
}






/*
杜子德爷爷用百元大钞击落洛谷服务器
刚从捐款活动回来的杜子德爷爷全然不顾身体的疲惫，【数据删除】

“但是有些【数据删除】，像洛谷，纵容OIer反对CCF的【数据删除】事业！【数据删除】 
杜子德爷爷从地上拣起一块石子，向天上一掷，顿时，天上发出一阵耀眼的火光。
“这就是洛谷的服务器，【数据删除】
我们D队的成员都为有杜子德爷爷这样的CCF主席感到自豪 
*/
