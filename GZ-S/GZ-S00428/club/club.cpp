//GZ-S00428 毕节梁才学校 赵纤茹
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PII;
int T,n;
PII a[100000][5];
int cnt[5];
int d[100000+10];
priority_queue<int,vector<int>,greater<int> > mi[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				int x;
				scanf("%d",&x);
				a[i][j]=(PII) {x,j};
			}
		}
		for(int i=1; i<=n; i++) {
			sort(a[i]+1,a[i]+3+1);
			d[i]=a[i][3].first-a[i][2].first;
		}
		for(int i=1; i<=3; i++) mi[i].push(0x3f3f3f3f);
		int ans=0;
		for(int i=1; i<=n; i++) {
			int id=a[i][3].second;
			int id2=0;
			if(cnt[id]<n/2) {
				ans+=a[i][3].first,cnt[id]++;
				if(mi[id].top()>d[i]) id2=a[i][2].second;
				mi[id].push(d[i]);
			} else {
				if(cnt[a[i][2].second]<n/2) {
					if(d[i]<mi[id].top()) {
						cnt[a[i][2].second]++;
						ans+=a[i][2].first;
					} else {
						cnt[id2]++;
						ans=ans-mi[id].top()+a[i][3].first;
						mi[id].push(d[i]);
						mi[id].pop();
					}
				} else ans+=a[i][1].first,cnt[a[i][1].second]++;
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}
