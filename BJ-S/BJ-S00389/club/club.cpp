#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n;
pair<int,int>a[MAXN][3];
void Do(int tt){
	cin>>n;
	ll ans=0;
	priority_queue<ll>q[3];
	rep(i,1,n){
		cin>>a[i][0].first>>a[i][1].first>>a[i][2].first;
		a[i][0].second=0,a[i][1].second=1,a[i][2].second=2;
		sort(a[i],a[i]+3);
		ans+=a[i][2].first;
		q[a[i][2].second].push(a[i][1].first-a[i][2].first);
	};
	int up=n/2;
	rep(i,0,2){
		while(q[i].size()>up){
			ans+=q[i].top();
			q[i].pop();
		}
	};
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	rep(i,1,T){
		Do(i);
	};
	return 0;
}
