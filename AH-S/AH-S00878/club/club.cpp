#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans;vector<int>a,b,c;
inline void solve(vector<int>d) {
	sort(d.begin(),d.end());
	for(int i=0;i<(int)d.size()-n/2;++i) ans-=d[i];
	return ;
}
inline void work() {
	scanf("%d",&n);ans=0;a.clear(),b.clear(),c.clear();
	for(int i=1,x,y,z;i<=n;++i) {
		scanf("%d%d%d",&x,&y,&z);
		if(x>y&&x>z) {
			ans+=x;
			a.push_back(min(x-y,x-z));
		}
		else if(y>z) {
			ans+=y;
			b.push_back(min(y-x,y-z));
		}
		else {
			ans+=z;
			c.push_back(min(z-x,z-y));
		}
	}
	if((int)a.size()>n/2) solve(a);
	if((int)b.size()>n/2) solve(b);
	if((int)c.size()>n/2) solve(c);
	printf("%d\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	return 0;
}