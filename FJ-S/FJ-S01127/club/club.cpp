#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,c[5];
struct date {
	int x,id;
};
struct node {
	date b[4];
} a[N],w[N];
bool cmp(node &p,node &q) {
	if(p.b[1].x==q.b[1].x) {
		if(p.b[2].x==q.b[2].x) return p.b[3].x>q.b[3].x;
		return p.b[2].x>q.b[2].x;
	}
	return p.b[1].x>q.b[1].x;
}
inline int solve(int fi,int se,int th,int m) {
	memset(c,0,sizeof(c));
	int sum=0;
	for(int i=1; i<=n; ++i) {
		if(c[a[i].b[fi].id]<m) c[a[i].b[fi].id]++,sum+=a[i].b[fi].x;
		else {
			if(c[a[i].b[se].id]<m) c[a[i].b[se].id]++,sum+=a[i].b[se].x;
			else c[a[i].b[th].id]++,sum+=a[i].b[th].x;
		}
	}
	return sum;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		int m=n/2,ans=0;
		for(int i=1; i<=n; ++i) {
			cin>>a[i].b[1].x>>a[i].b[2].x>>a[i].b[3].x;
			a[i].b[1].id=1,a[i].b[2].id=2,a[i].b[3].id=3;
			if(a[i].b[1].x<a[i].b[2].x) swap(a[i].b[1],a[i].b[2]);
			if(a[i].b[1].x<a[i].b[3].x) swap(a[i].b[1],a[i].b[3]);
			if(a[i].b[2].x<a[i].b[3].x) swap(a[i].b[2],a[i].b[3]);
		}
		sort(a+1,a+n+1,cmp);
		ans=max(ans,solve(1,2,3,m));
		ans=max(ans,solve(1,3,2,m));
		ans=max(ans,solve(2,1,3,m));
		ans=max(ans,solve(2,3,1,m));
		ans=max(ans,solve(3,1,2,m));
		ans=max(ans,solve(3,2,1,m));
		cout<<ans<<"\n";
	}
}
