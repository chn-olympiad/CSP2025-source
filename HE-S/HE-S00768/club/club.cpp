#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
constexpr int N=1e5+10;
int T,n;
ll ans;
struct node{
	int val,id;
	bool operator<(const node &x)const{
		return val>x.val;
	}
}a[5];
void solve(){
	ans=0;
	priority_queue<int,vector<int>,greater<int>> q[5];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[j].val;
			a[j].id=j;
		}
		sort(a+1,a+4);
		q[a[1].id].push(a[1].val-a[2].val);
		ans+=a[1].val;
	}
	for(int i=1;i<=3;i++)
		while(q[i].size()>size_t(n/2)){
			ans-=q[i].top();
			q[i].pop();
		}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
