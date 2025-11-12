#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int T,n,x,y,z;ll ans;
vector<int> v[3];
void solve(vector<int> v,int n){
	sort(v.begin(),v.end(),[&](int x,int y){return x>y;});
	while(v.size()>n)	ans-=v.back(),v.pop_back();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,v[0].clear(),v[1].clear(),v[2].clear(),ans=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z,ans+=max(x,max(y,z));
			if(x>=y&&x>=z)	v[0].emplace_back(x-max(y,z));
			else if(y>=x&&y>=z)	v[1].emplace_back(y-max(x,z));
			else	v[2].emplace_back(z-max(x,y));
		}
		int mx=(n>>1);
		if(v[0].size()>mx)	solve(v[0],mx);
		else if(v[1].size()>mx)	solve(v[1],mx);
		else if(v[2].size()>mx)	solve(v[2],mx);
		cout<<ans<<'\n';
	}
	return 0;
}
