#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N][5];
int fi[N],se[N];
int n,b,t;
priority_queue<int> q[5];
int cnt[5];
ll ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--) {
		cin>>n;
		b=n/2;
		for(int i=1;i<=n;i++) {
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				fi[i]=1;
				if(a[i][2]>=a[i][3]) se[i]=2;
				else se[i]=3;
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				fi[i]=2;
				if(a[i][1]>=a[i][3]) se[i]=1;
				else se[i]=3;
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) {
				fi[i]=3;
				if(a[i][1]>=a[i][2]) se[i]=1;
				else se[i]=2;
			}
		}
		//贡献为 max(a[i][fi]+max(a[j][se]-a[j][fi]),a[i][se])
		//即要求 a[j][se]-a[j][fi] 最大的 j(j in d) 
		for(int i=1;i<=n;i++) {
			if(cnt[fi[i]]>=b) {
				int t=q[fi[i]].top();
				if(a[i][fi[i]]+t>a[i][se[i]]) {
					q[fi[i]].pop();
					q[fi[i]].push(a[i][se[i]]-a[i][fi[i]]);
				}
				ans+=max(a[i][fi[i]]+t,a[i][se[i]]);
			} else {
				q[fi[i]].push(a[i][se[i]]-a[i][fi[i]]);
				ans+=a[i][fi[i]];
				cnt[fi[i]]++;
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=3;i++) {
			cnt[i]=0;
			while(!q[i].empty()) q[i].pop();
		}
	}
}
/*
期望得分：100+[48,80]+[10,25]+[8,20]=[166,225]
*/
