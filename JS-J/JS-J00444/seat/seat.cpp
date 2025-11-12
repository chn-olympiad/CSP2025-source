#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
const int inf = LLONG_MAX; 
const int mod = 1e9+7;
int n,m,cnt;
struct node {
	int sum,id;
}a[N];
bool cmp(node a,node b) {
	return a.sum>b.sum;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n*m;i++) {
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[++cnt].id==1) {
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=m;j>=1;j--) {
			if(a[++cnt].id==1) {
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
