#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

const int N = 1e4 + 4,M = 1e6 + 6;
int n,m,k,fa[N];
struct road{
	int u,v,w;
}r[M];

int find(int x){
	return fa[x] == x ? x : x = find(fa[x]);
}

bool cmp(road x,road y){
	return x.w < y.w;
}

int main(){
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++)fa[i] = i;
	if(k == 0){
		int ans = 0;
		for(int i = 1;i <= m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
		sort(r + 1,r + m + 1,cmp);
		//for(int i = 1;i <= m;i++)cout<<r[i].w;
		int cnt = 0;
		for(int i = 1;i <= m;i++){
			int x = find(r[i].u),y = find(r[i].v);
			if(x == y)continue;
			else{
				cnt++;
				fa[y] = x;
				ans += r[i].w;
			}
			if(cnt == n - 1)break;
		}
		cout<<ans<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
	return 0;
} 
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
