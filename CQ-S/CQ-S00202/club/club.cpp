#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=100005,mod=998244353;
const ll inf=0x3f3f3f3f;
#define pb push_back

int T,n;
struct node{
	int id;
	pair<int,int> mx1,mx2;
	bool operator<(const node&res)const{
		return mx1.first>res.mx1.first;
	}
}v[N]; 
pair<int,int> a[4];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1].first>>a[2].first>>a[3].first;
		a[1].second=1;a[2].second=2;a[3].second=3;
		sort(a+1,a+3+1);
		v[i].id=i;
		v[i].mx1=a[3];
		v[i].mx2=a[2];
	}
	sort(v+1,v+n+1);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[4];
	ll ans=0;
	for(int i=1;i<=n;i++){
		pair<int,int> m1=v[i].mx1,m2=v[i].mx2;
		if(q[m1.second].size()<(n/2)){
			ans+=m1.first;
			q[m1.second].push({m1.first-m2.first,i});
		}else{
			int ans1=0,ans2=0;
			ans1=m1.first-q[m1.second].top().first;ans2=m2.first;
			if(ans1>=ans2){
				int u=q[m1.second].top().second;
				q[m1.second].pop();
				q[m1.second].push({m1.first-m2.first,i});
				q[v[u].mx2.second].push({inf,u});
				ans+=ans1;
			}else{
				q[m2.second].push({inf,i});
				ans+=ans2;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 
	
	cin>>T;
	while(T--)solve();
	
	return 0;
} 
