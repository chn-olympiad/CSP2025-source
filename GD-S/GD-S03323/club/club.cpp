#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,dp[N][3];
int num[3];
struct cxm{
	int v,id;
}a[N][3];
bool cmp(cxm x , cxm y){
	return x.v>y.v;
}
vector <pair<int,int> > m[3];
void solve(){
	long long ans = 0;
	cin >> n;
	
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	m[0].clear();
	m[1].clear();
	m[2].clear();
	if(n>1000){
		int x,y,z;
		for(int i = 1 ; i <= n ; i++){
			cin >> x >> y >> z;
			ans += max(x,max(y,z));
		}
		cout << ans<<"\n";
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i][0].v >> a[i][1].v >> a[i][2].v;
		a[i][0].id=0;
		a[i][1].id=1;
		a[i][2].id=2;
		sort(a[i],a[i]+3,cmp);
		int p1 = a[i][0].id , p2 = a[i][1].id;
		num[p1]++;
		m[p1].push_back({a[i][0].v , a[i][1].v});
	}
	int p,nn,jjh,yhy;
	bool go=true;
	if(num[0] > n/2){
		p=0,nn=num[0],jjh=1,yhy=2;
	}else if(num[1] > n/2){
		p=1,nn=num[1],jjh=0,yhy=2;
	}else if(num[2] > n/2){
		p=2,nn=num[2],jjh=0,yhy=1;
	}else{
		jjh=1,yhy=2;
		for(auto k:m[0])ans += k.first;
		go = false;
	}
	bool vis[N]={0};
	if(go){
		for(int i = 1 ; i <= n/2 ; i++){
			int maxn = 0,px,py;
			for(int x = 0 ; x < nn ; x++){
				for(int y = 0 ; y < nn ; y++){
					if(x==y)continue;
					if(vis[x]||vis[y])continue; 
						int o=m[p][x].first,q=m[p][y].second;
					if(maxn < o+q){
						maxn = o+q;
						px=x;
						py=y;
					}
				}
			}
			ans += maxn;
			vis[px]=vis[py]=1;
		}
	}
	
	for(auto k : m[jjh])ans += k.first;
	for(auto k : m[yhy])ans += k.first;
	cout << ans << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)solve();
	return 0;
}
/*
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
