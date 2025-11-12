#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int Case,n,a[MAXN][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>Case;
	while(Case--){
		cin>>n;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[5];
		int cnt[5]={0,0,0,0,0};
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=max(a[i][2],a[i][3])){
				cnt[1]++;
				q[1].push({a[i][1]-max(a[i][2],a[i][3]),i});
				ans+=a[i][1];
			}else if(a[i][2]>=max(a[i][1],a[i][3])){
				cnt[2]++;
				q[2].push({a[i][2]-max(a[i][1],a[i][3]),i});
				ans+=a[i][2];
			}else if(a[i][3]>=max(a[i][1],a[i][2])){
				cnt[3]++;
				q[3].push({a[i][3]-max(a[i][1],a[i][2]),i});
				ans+=a[i][3];
			}
		}
		while(cnt[1]>n/2){
			int u=q[1].top().first,id=q[1].top().second;q[1].pop();
			cnt[1]--;ans-=u;
		}
		while(cnt[2]>n/2){
			int u=q[2].top().first,id=q[2].top().second;q[2].pop();
			cnt[2]--;ans-=u;
		}
		while(cnt[3]>n/2){
			int u=q[3].top().first,id=q[3].top().second;q[3].pop();
			cnt[3]--;ans-=u;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
