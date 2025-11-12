#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=998244353;
int n,m,c[N],p[N],cnt,ans;
char s[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	do {
		cnt=0;
		for(int i=1;i<=n;i++) {
			if(cnt>=c[p[i]]) cnt++;
			else if(s[i]=='0') cnt++;
		}
		if(n-cnt>=m) ans++;
	}
	while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
} 
