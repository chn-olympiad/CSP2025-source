#include<bits/stdc++.h>
using namespace std;
const int N=105;
#define int long long
int n,m;
struct dt {
	int v;
	bool fl;
}a[N*N];
bool cmp(dt a,dt b) {
	return a.v>b.v;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("A.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i].v;
		if(i==1) a[i].fl=1;
	}
	sort(a+1,a+1+n*m,cmp);
	int ps=0;
	for(int i=1;i<=n*m;i++) if(a[i].fl) ps=i;
//	cout<<ps<<endl;
	int l=(ps-1)/n+1,r=ps-n*(l-1);
	if(l%2==0) r=n-r+1;
	cout<<l<<" "<<r;
	return 0;
}
/*
2 2
99 100 97 98

*/
