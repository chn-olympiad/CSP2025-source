
// Surpassing never ends!

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+500;
long long read() {
	long long x=0;short f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-')f=-1;c=getchar(); }
	while(c>='0'&&c<='9') { x=x*10+c-'0';c=getchar(); }
	return x*f;
}
bool MB_1;

int T,n;

ll ans,a[N][4],cnt[4];
priority_queue<int > q[4];

bool MB_2;

signed main() {
//	cerr<<fabs(&MB_2-&MB_1)/(1024*1024)<<"MB\n";
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			int x=read(),y=read(),z=read();
			int mx=max({x,y,z});
			if(mx==x) cnt[1]++,q[1].push(max(y,z)-x);
			else if(mx==y) cnt[2]++,q[2].push(max(x,z)-y);
			else cnt[3]++,q[3].push(max(x,y)-z);
			ans+=mx;
		}
		if(cnt[1]>=n/2) {
			int dt=cnt[1]-n/2;
			while(dt--) ans+=q[1].top(),q[1].pop();
		}
		else if(cnt[2]>=n/2){
			int dt=cnt[2]-n/2;
			while(dt--) ans+=q[2].top(),q[2].pop();
		}
		else if(cnt[3]>=n/2){
			int dt=cnt[3]-n/2;
			while(dt--) ans+=q[3].top(),q[3].pop();
		}
		cout<<ans<<'\n';
		ans=0;cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=3;i++) while(q[i].size()) q[i].pop();
	}
	return 0;
}
