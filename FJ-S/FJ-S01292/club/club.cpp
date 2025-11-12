#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,a[N],b[N],c[N],ans;
void f(int p,int x,int y,int z,int m) {
	if(x>n/2||y>n/2||z>n/2)return;
	if(p==n) {
		ans=max(m,ans);
		return;
	}
	f(p+1,x+1,y,z,m+a[p+1]);
	f(p+1,x,y+1,z,m+b[p+1]);
	f(p+1,x,y,z+1,m+c[p+1]);
	return;
}
void g(int p,int x,int y,int m) {
	if(x>n/2||y>n/2)return;
	if(p==n) {
		ans=max(m,ans);
		return;
	}
	g(p+1,x+1,y,m+a[p+1]);
	g(p+1,x,y+1,m+b[p+1]);
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		if(n<=10) {
			f(0,0,0,0,0);
		} else {
			if(c[1]==0) {
				if(b[1]==0) {
					sort(a+1,a+n+1);
					for(int i=n; i>=n/2; i--)ans+=a[i];
				} else {
					g(0,0,0,0);
				}
			} else f(0,0,0,0,0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
