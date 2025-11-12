#include<bits/stdc++.h> 
#define int long long
#define up(i,l,r) for(int i=l; i<=r; ++i)
#define dn(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back

using namespace std;

const int N=100005;

int T, n, a[N], b[N], c[N], Ans;
vector<int> A, B, C;

void mian() {
	Ans=0, A.clear(), B.clear(), C.clear();
	cin >> n;
	up(i,1,n) {
		cin >> a[i] >> b[i] >> c[i];
		int rmq=max(max(a[i],b[i]),c[i]);
		Ans+=rmq;
		if(a[i]==rmq) {
			A.pb(min(a[i]-b[i],a[i]-c[i]));
		}
		else if(b[i]==rmq) {
			B.pb(min(b[i]-a[i],b[i]-c[i]));
		}
		else {
			C.pb(min(c[i]-a[i],c[i]-b[i]));
		}
	}
	if(B.size()>n/2) swap(A,B);
	if(C.size()>n/2) swap(A,C);
	int res=(int)A.size()-n/2;
	sort(A.begin(),A.end());
	for(int v:A) {
		if(res<=0) break;
		--res, Ans-=v;
	}
	cout << Ans << '\n'; 
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--) mian();
	return 0;
}
