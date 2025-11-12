#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct per {
	int d1,d2,d3;
} a[N];
int n,ans,t;
int club[10];

bool cmp(per x,per y) {
	int u1 = max(max(x.d1,x.d2),x.d3);
	int u2 = min(min(x.d1,x.d2),x.d3);
	int u = 2*u1+u2-x.d1-x.d2-x.d3;
	int v1 = max(max(y.d1,y.d2),y.d3);
	int v2 = min(min(y.d1,y.d2),y.d3);
	int v = 2*v1+v2-y.d1-y.d2-y.d3;
	return u>v;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		memset(club,0,sizeof(club));
		ans = 0;
		cin >> n;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].d1,&a[i].d2,&a[i].d3);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1; i<=n; i++) {
			pair<int,int> a1,a2,a3;
			a1.first = a[i].d1,a2.first=a[i].d2,a3.first=a[i].d3;
			a1.second = 1,a2.second=2,a3.second=3;
			if(a1.first < a2.first) swap(a1,a2);
			if(a2.first < a3.first) swap(a2,a3);
			if(a1.first < a2.first) swap(a1,a2);
			if(club[a1.second]<n/2) {
				ans += a1.first;
				club[a1.second]++;
			} else if(club[a2.second]<n/2) {
				ans += a2.first;
				club[a2.second]++;
			} else{
				ans += a3.first;
				club[a3.second]++;
			}
		}
		printf("%d\n",ans);
	}
}
//tarjan图不一定连通，注意数据范围开ll,最后要把freopen注释删掉

