#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],ans,sum[3];
void dfs(int st,int c1,int c2,int c3,int cur) {
	if(c1>n/2||c2>n/2||c3>n/2) return;
	if(st==n+1) {
		cout<<c1<<' '<<c2<<' '<<c3<<' '<<cur<<endl;
		ans=max(ans,cur);
		return;
	}
	dfs(st+1,c1+1,c2,c3,cur+a[0][st]);
	dfs(st+1,c1,c2+1,c3,cur+a[1][st]);
	dfs(st+1,c1,c2,c3+1,cur+a[2][st]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		int h=0,g;
		for(int i=1; i<=n; i++) {
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			sum[0]+=a[0][i];
			sum[1]+=a[1][i];
			sum[2]+=a[2][i];
		}
		for(int i=0; i<3; i++) {
			if(sum[i]==0) h++;
			if(sum[i]>0) g=i;
		}
		if(h==2) {
			sort(a[g]+1,a[g]+n+1,greater<int>());
			for(int i=1; i<=n/2; i++) {
				ans+=a[g][i];
			}
			cout<<ans;
		} else {
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
