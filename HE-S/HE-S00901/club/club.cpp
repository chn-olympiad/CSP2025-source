//I am a CSP-Jer, I'm afraid I can't solve these problems.
#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][5];
int cnt[4];
long long ans;
priority_queue<int> Q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--) {
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		while(!Q.empty()) Q.pop();
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++) {
			int s=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)
				if(a[i][j]==s) {
					ans+=a[i][j];
					cnt[j]++;
					break;
				}
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) {
			cout<<ans<<endl;
			continue;
		}
		int sss=max(cnt[1],max(cnt[2],cnt[3]));
		for(int kkk=1;kkk<=3;kkk++) {
			if(cnt[kkk]<=n/2) continue;
			for(int i=1;i<=n;i++) {
				if(a[i][kkk]!=max(a[i][1],max(a[i][2],a[i][3])))
					continue;
				int ddd=-1e9;
				for(int j=1;j<=3;j++) {
					if(j==kkk) continue;
					ddd=max(ddd,a[i][j]-a[i][kkk]);
				}
				Q.push(ddd);
			}
		}
		for(int i=sss;i>n/2;i--) {
			ans+=Q.top();
			Q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
