#include<bits/stdc++.h>
using namespace std;
long long n,m;
int t;
long long a[100000+5][3];
struct node1 {
	long long m;
	int d;
}d[100000+5];
struct node {
	long long m1,m2,m3;
	int d;
}b[100000+5];
bool cmp(node x,node y){
	int maxn=-1,bj=0;
	if(x.m1+y.m2>maxn) {
		maxn=x.m1+y.m2;
		bj=1;
	}
	if(x.m1+y.m3>maxn) {
		maxn=x.m1+y.m3;
		bj=2;
	}
	if(x.m2+y.m3>maxn) {
		maxn=x.m2+y.m3;
		bj=3;
	}
	if(x.m2+y.m1>maxn) {
		maxn=x.m2+y.m1;
		bj=4;
	}
	if(x.m3+y.m1>maxn) {
		maxn=x.m3+y.m1;
		bj=5;
	}
	if(x.m3+y.m2>maxn) {
		maxn=x.m3+y.m2;
		bj=6;
	}
	if(bj==1 and bj==2 and bj==3) {
		return 0;
	}
	if(bj==4 and bj==5 and bj==6) {
		return 1;
	}
}
void solve() {
	m=n/2;
	long long ans=0;
	long long i,j,k;
	for(i=1;i<=n;i++) {
		cin>>b[i].m1>>b[i].m2>>b[i].m3;
		b[i].d=i;
	}
	sort(b+1,b+n+1,cmp);
	for(i=1;i<=m;i++) {
		ans+=b[i].m1;
	}
	for(i=m+1;i<=n;i++) {
		ans+=b[i].m2;
	}
	cout<<ans<<'\n';
}
void solve1() {
	long long i;
	for(i=1;i<=n;i++) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		long long maxn=-1;
		int maxd;
		if(maxn<a[i][1]) {
			maxn=a[i][1];
			maxd=1;
		} 
		if(maxn<a[i][2]) {
			maxn=a[i][2];
			maxd=2;
		}
		if(maxn<a[i][3]) {
			maxn=a[i][3];
			maxd=3;
		}
		d[i].m=maxn;
		d[i].d=maxd;
	}
	long long d1=0,d2=0,d3=0;
	for(i=1;i<=n;i++) {
		if(d[i].d==1) d1+=d[i].m;
		if(d[i].d==2) d2+=d[i].m;
		if(d[i].d==3) d3+=d[i].m;
	}
	cout<<d1+d2+d3<<'\n';
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>n;
		if(n==2) solve();
		else solve1();
	}
	return 0;
}
