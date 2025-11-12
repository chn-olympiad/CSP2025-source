#include <bits/stdc++.h>
using namespace std;

struct node {
	int a,b,c,k,g;
} a[100011];

int t,n,ans;
int s[4];

bool cmp(const node &x,const node &y) {
	return x.g > y.g;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			int ma = max(a[i].a,max(a[i].b,a[i].c));
			if (a[i].a == ma)
				a[i].k = max(a[i].b,a[i].c);
			else if (a[i].b == ma)
				a[i].k = max(a[i].a,a[i].c);
			else
				a[i].k = max(a[i].a,a[i].b);
			a[i].g = ma - a[i].k;
		}
		sort(a + 1,a + n + 1,cmp);
		ans = 0;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++) {
			int ma = max(a[i].a,max(a[i].b,a[i].c));
			int id;
			if (ma == a[i].a)
				id = 1;
			else if (ma == a[i].b)
				id = 2;
			else
				id = 3;
			if (s[id] < n / 2) {
				s[id]++;
				ans += ma;
			}
			else {
				ans += a[i].k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
