#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node {
	int v,id;
	bool operator < (const node &A) const {
		return v>A.v;
	}
}a[100000];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; ++i) cin>>a[i].v,a[i].id=i;
	sort(a+1,a+n*m+1);
	int x=a[1].id;
	int p=x/n,q=x%n;
	if(!q) return cout<<p<<" "<<n,0;
	p++;
	cout<<p<<" "<<((p&1)?q:n-q+1);
}
