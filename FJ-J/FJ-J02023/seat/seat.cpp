#include<bits/stdc++.h>
using namespace std;
const int MAXN=10*10*10+5;
int a[MAXN];
struct node {
	int sc;
	int lie,hang;
	int id;
}b[MAXN];
bool cmp(node aa,node bb) {
    return aa.sc>bb.sc;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>a[i];
		b[i].id=i;
		b[i].sc=a[i];
	}
	sort(b+1,b+1+n*m,cmp);
	b[1].lie=1; b[1].hang=1;
	int lstl=1,lsth=1;
	bool ni=0;
	for (int i=2;i<=n*m;i++) {
		if (lsth==n&&!ni) {
			ni=1;
			b[i].hang=n;
			b[i].lie=lstl+1;
		}else if (ni&&lsth!=1) {
			b[i].hang=lsth-1;
			b[i].lie=lstl;
		}else if (!ni&&lsth!=n) {
			b[i].hang=lsth+1;
			b[i].lie=lstl;
		}else if (ni&&lsth==1) {
			ni=0;
			b[i].hang=1;
			b[i].lie=lstl+1;
		}
		lstl=b[i].lie; lsth=b[i].hang;
	}
	for (int i=1;i<=n*m;i++) {
		if (b[i].id==1) {
			cout<<b[i].lie<<' '<<b[i].hang<<'\n';
			return 0;
		}
	}
}   
