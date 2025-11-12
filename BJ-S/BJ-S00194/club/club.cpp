#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+100;
int n,t,a[MAXN][5],ans,spa[MAXN];
bool spA=1,spB=1;
bool cmp(int a,int b) {
	return a>b;
}
void dfs(int dep,int club1,int club2,int club3,int score) {
	if(dep>=n+1) {
		ans=max(ans,score);
	}
	if(club1<n/2) dfs(dep+1,club1+1,club2,club3,score+a[dep][1]);
	if(club2<n/2) dfs(dep+1,club1,club2+1,club3,score+a[dep][2]);
	if(club3<n/2) dfs(dep+1,club1,club2,club3+1,score+a[dep][3]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		spA=1;
		spB=1;
		ans=0;
		memset(spa,0,sizeof(spa));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0) spA=0;
			if(a[i][3]!=0) spB=0;
		}
		if(n<=10) {
			dfs(1,0,0,0,0);
		}
		else if(spA) {
			for(int i=1;i<=n;i++) spa[i]=a[i][1];
			sort(spa+1,spa+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=spa[i];
		}
		else {
			for(int i=1;i<=n;i++) {
				sort(a[i]+1,a[i]+1+3,cmp);
				ans+=a[i][1];
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
