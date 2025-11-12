#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=1e5+10;
const int maxm=1e6+10;
const int mod=1e9+7;
int n,m,a[maxn];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++) cin >> a[i];
	int k=a[1];
	sort(a+1,a+n*m+1);
	int d=n*m-(lower_bound(a+1,a+n*m+1,k)-a)+1;
	cout << (d-1)/n+1 << " " << (((d-1)/n+1)%2==1?(d-1)%n+1:n-(d-1)%n);
	return 0;
}
