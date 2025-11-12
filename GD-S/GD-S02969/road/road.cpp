#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1000,M=1.2e6+1000;
typedef long long ll;
int n,m,k;
struct node {
	int u,v,w;
} E[M],EE[M];
int Fa[N],C[20],A[20][N],B[20];
int find(int x) {
	if(x==Fa[x]) return x;
	else return Fa[x]=find(Fa[x]);
}
ll get() {
	for(int i=1;i<=n;i++) Fa[i]=i;
	sort(E+1,E+1+m,[&](node x,node y) {
		return x.w<y.w;
	});
	ll ans=0;
	for(int i=1;i<=m;i++) {
		int a=find(E[i].u),b=find(E[i].v);
		if(a==b) continue;
		Fa[a]=b;
		ans+=E[i].w;
	}
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>E[i].u>>E[i].v>>E[i].w;
		EE[i]={E[i].u,E[i].v,E[i].w};
	}
	int flcnt=0;
	for(int i=1;i<=k;i++) {
		cin>>C[i]; flcnt+=(C[i]==0);
		for(int j=1;j<=n;j++) {
			cin>>A[i][j];
			if(A[i][j]==0) {
				flcnt+=(!B[i]);
				B[i]=j;
			}
		}
	}
	if(flcnt==k*2) { 
		for(int i=1;i<=k;i++) {
			for(int j=1;j<=n;j++) {
				if(j==B[i]) continue;
				E[++m]={B[i],j,A[i][j]};
			}
		}
		cout<<get(); return 0;
	}
	else {
		int nn=n,mm=m;
		ll ans=1e18;
//		sort(EE+1,EE+1+m,[&](node x,node y) {
//			return x.w<y.w;
//		});
		for(int i=0;i<(1<<k);i++) {
			n=nn;m=mm;
			ll wzh=0;
			for(int j=1;j<=m;j++)
				E[j]=EE[j];
			for(int j=0;j<k;j++) {
				if(i&(1<<j)) {
					n++;
					for(int l=1;l<=n;l++) {
						E[++m]={n,l,A[j+1][l]};
					}
					wzh+=C[j+1];
				}
			}
			ans=min(ans,wzh+get());
		}
		cout<<ans<<endl;
	}
}

