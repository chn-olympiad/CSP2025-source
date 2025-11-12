//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;

vector<pair<int,int> > a[MAXN];
int cnt[3];
priority_queue<int,vector<int>,greater<int> > st;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while (t--){
		while (st.size()) st.pop();
		int n;
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) a[i].clear();
		for (int i=1;i<=n;i++){
			for (int j=0;j<=2;j++){
				int tmp;
				scanf("%lld",&tmp);
				a[i].push_back({tmp,j});
			}
			sort(a[i].begin(),a[i].end(),greater<pair<int,int> >());
		}
		cnt[0]=cnt[1]=cnt[2]=0;
		int ans=0;
		for (int i=1;i<=n;i++) cnt[a[i][0].second]++,ans+=a[i][0].first;
		if (cnt[0]>n/2){
			for (int i=1;i<=n;i++)
				if (a[i][0].second==0)
					st.push(a[i][0].first-a[i][1].first);
			while (cnt[0]>n/2){
				ans-=st.top();
				st.pop();
				cnt[0]--;
			}
		}
		if (cnt[1]>n/2){
			for (int i=1;i<=n;i++)
				if (a[i][0].second==1)
					st.push(a[i][0].first-a[i][1].first);
			while (cnt[1]>n/2){
				ans-=st.top();
				st.pop();
				cnt[1]--;
			}
		}
		if (cnt[2]>n/2){
			for (int i=1;i<=n;i++)
				if (a[i][0].second==2)
					st.push(a[i][0].first-a[i][1].first);
			while (cnt[2]>n/2){
				ans-=st.top();
				st.pop();
				cnt[2]--;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}

