#include<bits/stdc++.h>
using namespace std;
const int ma=100005;
int n;
int a[ma],b[ma],c[ma];
int cnt[4];
int ans=0;
void s(int dep,int sum) {
	if(dep==n+1) {
		ans=max(sum,ans);
		return ;
	}
	if(cnt[1]<n/2) {
		cnt[1]++;
		s(dep+1,sum+a[dep]);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		s(dep+1,sum+b[dep]);
		cnt[2]--;
	}
	if(cnt[3]<n/2) {
		cnt[3]++;
		s(dep+1,sum+c[dep]);
		cnt[3]--;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ans=0;
		for(int i=1; i<=n; i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		s(1,0);
		printf("%d\n",ans);
	}


	return 0;
}
