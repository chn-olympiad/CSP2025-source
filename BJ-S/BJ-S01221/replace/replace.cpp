#include<bits/stdc++.h>
#define mk make_pair
#define pii pair<string,string>
using namespace std;
const int N = 3e6 + 5;
int n,q;
string s1[N],s2[N],x,y,zx = "",zy="";
map<pii,bool> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q ;
	for(int i=1;i<=n;i++) cin >> s1[i] >> s2[i],mp[mk(s1[i],s2[i])]=1;
	for(int i=1;i<=q;i++) {
		cin >> x >> y ;
		if(x.size() != y.size()) {cout << 0 << "\n";continue;}
		int len = x.size(),res = 0;
		x='#'+x,y='#'+y;
		int stx = 1,edx = len;
		while(x[stx]==y[stx]&&stx<=len) stx++;
		while(x[edx]==y[edx]&&edx>=1) edx--;
		stx--,edx++;
		// cout << stx << " " << edx << "\n";
		for(int j=1;j<=stx+1;j++){
			zx="",zy="";
			for(int k=j;k<=len;k++) {
				zx=zx+x[k],zy=zy+y[k];
				if(k>=edx-1&&mp[mk(zx,zy)]==1) res ++; 
			}
		} 
		cout << res << "\n";
	}

	return 0;
}