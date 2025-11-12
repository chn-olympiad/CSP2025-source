#include<bits/stdc++.h>
using namespace std;
int n,to[500005],ans,last;
long long a[500005],k,b[500005];
bool vis[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1; i<=n; i++) {
		int r=i;
		while(b[i]!=k and r<=n) {
			r++;
			b[i]^=a[r];
		}
		to[i]=r;
		if(r<=n)last=r;
	}
	to[n+1]=n+1;
	int now=1,res=0;
	while(now<=n) {
		if(now>last and to[now]>n) {
			res--;
			now=n+1;
		}
		res++;
		vis[now]=1;
		int mx=to[now],nx=to[now];
		for(int j=now; j<=mx; j++)nx=min(nx,to[j]);
		now=nx+1;
	}
	ans=max(ans,res);
	cout<<ans;
}
