#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=1e5+10;

int n,m,v,p[N];

inline bool cmp(int q,int w) {return q>w;}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>p[i]; v=p[1];
	sort(p+1,p+n*m+1,cmp);
	for(int i=1;i<=n*m;++i) if(p[i]==v) {v=i; break;}
	cout<<((v-1)/n+1)<<" ";
	if(((v-1)/n+1)%2) cout<<v-(v-1)/n*n;
	else cout<<n-(v-(v-1)/n*n)+1;
	return 0;
}