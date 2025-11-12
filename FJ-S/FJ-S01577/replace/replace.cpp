#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200010][3];
int ll[200010];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for (register int i=1; i<=n; ++i) {
		cin>>s[i][1]>>s[i][2];
		ll[i]=s[i][1].size();
		s[i][1]='!'+s[i][1];
		s[i][2]='!'+s[i][2];
	}
	while (q--) {
		string a,b;
		int ans=0;
		cin>>a>>b;
		if (a.size()!=b.size());
		else {
			int len=a.size();
			a='!'+a;
			b='!'+b;
			int l=1,r=len;
			for (register int i=1; i<=len; ++i) {
				if (a[i]!=b[i]) {
					l=i;
					break;
				}
			}
			for (register int i=len; i>=1; --i) {
				if (a[i]!=b[i]) {
					r=i;
					break;
				}
			}
			for (register int i=1; i<=n; ++i) {
				if(ll[i]<r-l+1);
				else {
					int h=ll[i]-(r-l+1),q=-1;
					for (register int j=max(l-h,1ll); j<=l; ++j) {
						if (s[i][1][1]==a[j]) {
							q=j;
							break;
						}
					}
					if (q==-1) {
						continue;
					}
					int oppo[100],k=0;
					for (register int o=q; o<=l; ++o) {
						bool bbb=0;
						for (register int j=o,sq=1; j<=o+ll[i]-1; ++j,++sq) {
							if (s[i][1][sq]!=a[j]) {
								break;
							}
							if (j==o+ll[i]-1) {
								bbb=1;
							}
						}
						if (bbb==1) {
							oppo[++k]=o;
						}
					}
					for (register int j=1; j<=k; ++j) {
						bool bbb=0;
						for (register int p=oppo[j],sq=1; p<=oppo[j]+ll[i]-1; ++p,++sq) {
							if (s[i][2][sq]!=b[p]) {
								break;
							}
							if (p==oppo[j]+ll[i]-1) {
								bbb=1;
							}
						}
						if (bbb==1) {
							++ans;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
