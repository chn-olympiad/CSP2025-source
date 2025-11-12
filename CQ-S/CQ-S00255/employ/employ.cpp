#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,ans,cnt;
char s[N];
int c[N];
int p[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	int sum=0;
	for(int i=1;i<=n;i++) sum+=(s[i]=='0');
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i,cnt+=(c[i]==0);
	if(n-max(sum,cnt)<m) {
		cout<<0;
		return 0;
	}
	do {
		int now=0;
		for(int i=1;i<=n;i++) {
			int x=p[i];
			if(now>=c[x]) ++now;
			else if(s[i]=='0') ++now;
		}
		if(now<=n-m) ++ans;
	} while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
