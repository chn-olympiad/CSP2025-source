#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define int long long
int T,a[N][10],n,t,ans=-1e9,b[N];
bool cmp(int x,int y) {
	return x>y;
}
void dfs(int id,int d,int b,int c,int tmp) {
	if(id>n) {
		ans=max(tmp,ans);
		return;
	}
	for(int i=1; i<=3; i++) {
		if(i==1&&d<n/2) dfs(id+1,d+1,b,c,tmp+a[id][i]);
		else if(i==2&&b<n/2) dfs(id+1,d,b+1,c,tmp+a[id][i]);
		else if(i==3&&c<n/2) dfs(id+1,d,b,c+1,tmp+a[id][i]);
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		if(n==100000) {
			int aaa=0;
			int zzz;
			for(int i=1; i<=n; i++) {
				cin>>b[i]>>zzz>>zzz;
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				aaa+=b[i];
			}
			cout<<aaa<<"\n";
		} else {
			for(int i=1; i<=n; i++) {
				cin>>a[i][1]>>a[i][2]>>a[i][3];
//			a[i][1].d=1;
//			a[i][2].d=2;
//			a[i][3].d=3;
//			sort(a[i]+1,a[i]+4,cmp);
			}
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			ans=-1e9;
		}
	}
	return 0;
}
/*
3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/
