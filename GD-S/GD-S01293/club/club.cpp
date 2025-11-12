#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN][5],cnt[5];
priority_queue<int ,vector<int> , greater<int> >pq_club1;
priority_queue<int ,vector<int> , greater<int> >pq_club2;
priority_queue<int ,vector<int> , greater<int> >pq_club3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
			}
		}
		int k=n/2;
		long long ans=0;
		for(int i=1; i<=n; i++) {
			int ma=max(max(a[i][1],a[i][2]),a[i][3]),num=0;
			if(ma==a[i][1])num=1;
			else if(ma==a[i][2])num=2;
			else num=3;
			if(num==1) {
				if(cnt[1]==k) {
					int tmp=pq_club1.top();
					if(tmp<a[i][1]-max(a[i][2],a[i][3])) {
						pq_club1.pop();
						ans-=tmp;
						ans+=a[i][1];
						pq_club1.push(a[i][1]-max(a[i][2],a[i][3]));
					} else ans+=max(a[i][2],a[i][3]);
				} else {
					ans+=a[i][1];
					pq_club1.push(a[i][1]-max(a[i][2],a[i][3]));
					cnt[1]++;
				}
			} else if(num==2) {
				if(cnt[2]==k) {
					int tmp=pq_club2.top();
					if(tmp<a[i][2]-max(a[i][1],a[i][3])) {
						pq_club2.pop();
						ans-=tmp;
						ans+=a[i][2];
						pq_club2.push(a[i][2]-max(a[i][1],a[i][3]));
					} else ans+=max(a[i][1],a[i][3]);
				} else {
					ans+=a[i][2];
					pq_club2.push(a[i][2]-max(a[i][1],a[i][3]));
					cnt[2]++;
				}
			} else if(num==3) {
				if(cnt[3]==k) {
					int tmp=pq_club3.top();
					if(tmp<a[i][3]-max(a[i][2],a[i][1])) {
						pq_club3.pop();
						ans-=tmp;
						ans+=a[i][3];
						pq_club3.push(a[i][3]-max(a[i][1],a[i][2]));
					} else ans+=max(a[i][1],a[i][2]);
				} else {
					ans+=a[i][3];
					pq_club3.push(a[i][3]-max(a[i][1],a[i][2]));
					cnt[3]++;
				}
			}
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		cout<<ans<<endl;
		memset(cnt,0,sizeof cnt);
		while(!pq_club1.empty())pq_club1.pop();
		while(!pq_club2.empty())pq_club2.pop();
		while(!pq_club3.empty())pq_club3.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

