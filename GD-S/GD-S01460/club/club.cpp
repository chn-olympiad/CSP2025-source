#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll maxn=1e5+10,inf=0x3f3f3f3f;
ll n,a[maxn][4],ans;
ll t;
void solve(){
	ans=0;
	priority_queue<PLL,vector<PLL>,greater<PLL> >q[4];//d id
	cin>>n;
	for(int i=1;i<=n;i++){
		ll id=0,d=inf;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
//			cout<<a[i][j]<<' ';
			if(a[i][j]>a[i][id])id=j;
			
		}//cout<<id<<' ';
		for(int j=1;j<=3;j++){
			if(j!=id)d=min(d,a[i][id]-a[i][j]);
		}ans+=a[i][id];
//		cout<<d<<' ';
		q[id].push(make_pair(d,i));
//		cout<<i<<' ';
	}
	
	for(int i=1;i<=3;i++){
		while(q[i].size()>n/2){
			ans-=q[i].top().first;
			q[i].pop();
		}
	}cout<<ans<<endl;
}
int main(){
//	freopen("club5.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)solve();
	return 0;
} /*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
