#include <bits/stdc++.h>
using namespace std;
long long n,k,alx,px,ans,lq,fl,ia;
map <long long,long long> m;
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	m[0]=0;
	for (int i=1;i<=n;i++) {
		cin>>ia;
		alx^=ia;
		px=alx^k;
		if (m.count(px)) {
			fl=m[px];
			if (fl>=lq) {
				lq=i;
				ans++;
			}
		}
		m[alx]=i;
	}
	cout<<ans;
	return 0;
}

