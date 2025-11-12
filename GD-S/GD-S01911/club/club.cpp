#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int T,n,a1[maxn],a2[maxn],a3[maxn];
struct qwq{
	int val,del,nxt,nval;
	bool operator < (const qwq &r) const{
		return del<r.del; 
	}
};
priority_queue<qwq>q[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a1[i]>>a2[i]>>a3[i];
			int maxx=max(a1[i],max(a2[i],a3[i]));
			if(maxx==a1[i]){
				if(a2[i]>a3[i]) q[1].push({a1[i],a1[i]-a2[i],2,a2[i]});
				else q[1].push({a1[i],a1[i]-a3[i],3,a3[i]});
			}else if(maxx==a2[i]){
				if(a1[i]>a3[i]) q[2].push({a2[i],a2[i]-a1[i],1,a1[i]});
				else q[2].push({a2[i],a2[i]-a3[i],3,a3[i]});
			}else{
				if(a1[i]>a2[i]) q[3].push({a3[i],a3[i]-a1[i],1,a1[i]});
				else q[3].push({a3[i],a3[i]-a2[i],2,a2[i]});
			}
		}
		int op=-1;
		if(q[1].size()>n/2) op=1;
		else if(q[2].size()>n/2) op=2;
		else if(q[3].size()>n/2) op=3;
		if(op>-1){
			for(int i=1;i<=n/2;i++){
				qwq tmp=q[op].top();
				ans+=tmp.val;
				q[op].pop();
			}
			while(!q[op].empty()) {
				qwq tmp=q[op].top();
				q[tmp.nxt].push({tmp.nval,tmp.del,tmp.nxt,tmp.nval});
				q[op].pop();
			}
		}
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				if(i!=op) ans+=q[i].top().val;
				q[i].pop();
			}
		}
		cout<<ans<<'\n';
	}//ÎÒÊÇÉµ±Æ 
	return 0;
}
