#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5;
ll n,q;
string stra[maxn],strb[maxn];
ll cnt_size[maxn];
int main() {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1; i<=n; i++) 
		cin>>stra[i]>>strb[i], cnt_size[i]=stra[i].size();
	while (q--) {
		string a,b;
		cin>>a>>b;
		if (a.size()!=b.size()) 
			{ cout<<0<<"\n"; continue; }
		ll ans=0, Asize=a.size();
		for (int i=0; i<Asize; i++) {
			for (int j=1; j<=n; j++) {
				if (i+cnt_size[j]-1>=Asize) continue;
				string check=a;
				for (int k=0; k<cnt_size[j]; k++)
					check[i+k]=strb[j][k];
				if (check==b) ans++;
			}
			if (a[i]!=b[i]) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
