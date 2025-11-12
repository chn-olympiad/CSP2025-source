#include<bits/stdc++.h>
#define eps 1e-6
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MOD 998244353
#define MAXN 300005
int n,a[MAXN][5],cnt[100],S;
priority_queue<int,vector<int>,greater<int> >s[3];
void clr(){
	cnt[0]=cnt[1]=cnt[2]=S=0;
	for(int i=0;i<3;i++)
		while(!s[i].empty())s[i].pop();
}
void solve(){
	scanf("%d",&n);
	clr();
	for(int i=1;i<=n;i++){
		set<pii>see;
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			see.insert({a[i][j],j});
		}
		auto p=*prev(see.end());
		cnt[p.se]++,S+=p.fi;
		s[p.se].push(p.fi-next(see.begin())->fi);
	}
	int L=n/2;
	if(max({cnt[0],cnt[1],cnt[2]})>L){
		int id=0;
		for(int j=0;j<3;j++)
			if(cnt[j]>L)id=j;
		for(int _=1;_<=cnt[id]-L;_++){
			S-=s[id].top(),s[id].pop();
		}
	}
	printf("%d\n",S);
}
signed main(){
	// auto ST=clock();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	// auto EN=clock();
	// cerr<<(EN-ST)*1.0/CLOCKS_PER_SEC<<endl;

	return 0;
}