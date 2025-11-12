#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,ans=-1;
int a[N],b[N],c[N];
struct nod {
	int x,y,z;
}k[N];
void dfs(int step,int sum,int cntx,int cnty,int cntz) {
	if(step==n+1) {
		ans=max(ans,sum);
		return ;
	}
	for(int i=1; i<=3; i++) {
		if(i==1&&cntx<n/2) {
			dfs(step+1,sum+a[step],cntx+1,cnty,cntz);
		} else if(i==2&&cnty<n/2) {
			dfs(step+1,sum+b[step],cntx,cnty+1,cntz);
		} else if(i==3&&cntz<n/2) {
			dfs(step+1,sum+c[step],cntx,cnty,cntz+1);
		} else continue;
	}
	return ;
}
bool cmp(nod n1,nod n2) {
	return n1.x>n2.x;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		if(n<=10) {
			for(int i=1; i<=n; i++) cin>>a[i]>>b[i]>>c[i];
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		} else {
			int flag=0;
			for(int i=1; i<=n; i++) {
				cin>>k[i].x>>k[i].y>>k[i].z;
				if(k[i].y!=0||k[i].z!=0) flag=1;
			}
			if(flag==0) {
				sort(k+1,k+1+n,cmp);
				int ans=0;
				for(int i=1; i<=n/2; i++) ans+=k[i].x;
				cout<<ans<<endl;
				continue;
			}
		}
	}
	return 0;
}
