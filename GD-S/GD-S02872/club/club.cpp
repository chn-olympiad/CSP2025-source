#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
#define fi first
#define se second
using ll=long long;
using pii=pair<int,int>;
const int N=1e5+5;
int n,ans;
struct node {
	pii x[3];
}a[N];
multiset<int> s[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;scanf("%d",&_);
	while(_--) {
		for(int i=0;i<3;i++) s[i].clear();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) a[i].x[j].se=j;
		}
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].x[0].fi,&a[i].x[1].fi,&a[i].x[2].fi);
		for(int i=1;i<=n;i++) {
			sort(a[i].x,a[i].x+3);
			int x=a[i].x[2].fi,y=a[i].x[2].se;
			s[y].insert(x-a[i].x[1].fi);
			ans+=x;
		}
		for(int i=0;i<3;i++) {
			while(s[i].size()>n/2) {
				ans-=*s[i].begin();
				s[i].erase(s[i].begin());
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
“¿æ…“≈∫∂¿Î≥° 
*/
