#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

struct S {
	int id;
	int x1,x2,x3;
} l[N];

int n,ans;

void dfs(int k,int s,int c1,int c2,int c3) {
	if(k==n+1) {
		ans=max(ans,s);
		return ;
	}
	if(c1<n/2) dfs(k+1,s+l[k].x1,c1+1,c2,c3);
	if(c2<n/2) dfs(k+1,s+l[k].x2,c1,c2+1,c3);
	if(c3<n/2) dfs(k+1,s+l[k].x3,c1,c2,c3+1);
	return ;
}

void sol() {
	ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>l[i].x1>>l[i].x2>>l[i].x3;
		l[i].id=i;
	}
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
	return;
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) sol();
	return 0;
}
