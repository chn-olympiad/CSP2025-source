#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef long long ll;
int n,a[MAXN][4],d[MAXN];
deque<pair<int,int> > p[4];
inline void solve(){
	scanf("%d",&n);
	ll res=0;
	for(int i=1;i<=n;++i){
		int Max=0,Cmax=0;
		for(int j=1;j<=3;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]>=a[i][Max]){
				Cmax=Max;
				Max=j;
			}else if(a[i][j]>=a[i][Cmax]){
				Cmax=j;
			}
		}
		p[Max].push_back(make_pair(a[i][Max]-a[i][Cmax],i));
		res+=a[i][Max];
	}
	for(int i=1;i<=3;++i){
		if(p[i].size()>(n>>1)){
			sort(p[i].begin(),p[i].end());
			while(p[i].size()>(n>>1)){
				res-=p[i].front().first;
				p[i].pop_front();
			}
			break;
		}
	}
	printf("%lld\n",res);
	p[1].clear();
	p[2].clear();
	p[3].clear();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	} 
	return 0;
}
/*
input:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
