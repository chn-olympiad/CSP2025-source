#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)

using namespace std;
const int MAXN=1E5+10;
struct p {
	int a,b,c;
} x[MAXN];
int qz[MAXN];
int T,n,ans=-0x3f3f3f3f;
void dfs(int v,int a,int b,int c,int t) {
	if(a>n/2 or b>n/2 or c>n/2) {
		return;
	}
	if(v>n) {
		ans=max(ans,t);
		return;
	}
	dfs(v+1,a+1,b,c,t+x[v].a);
	dfs(v+1,a,b+1,c,t+x[v].b);
	dfs(v+1,a,b,c+1,t+x[v].c);
}
bool cmp1(p x,p y) {
	return x.a>y.a;
}
bool cmp2(p x,p y) {
	return x.a-x.b>y.a-y.b;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=-0x3f3f3f3f;
		cin>>n;
		bool nb=0,nc=0;
		for(int i=1; i<=n; i++) {
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b!=0)nb=1;
			if(x[i].c!=0)nc=1;
		}
		if(n<=30) {
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		} else {
			if(nc==0) {
				ans=0;
				sort(x+1,x+n+1,cmp2);
				fo(i,1,n/2) {
					ans+=x[i].a;
				}
				of(i,n,n/2+1) {
					ans+=x[i].b;
				}
				cout<<ans<<'\n';
			} else {
				ans=0;
			}
		}
	}
	return 0;
}
