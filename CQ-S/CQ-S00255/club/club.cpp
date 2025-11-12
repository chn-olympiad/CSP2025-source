/*
T1

贪心地选择满意度最高的部门，然后如果出现了多于 \frac{n}{2} 的情况，将多余的贪心调整到其它部门，此时一定合法。 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
void Solve() {
	ll ans=0;
	vector<int> b[3];
	cin>>n;
	for(int i=1,x,y,z;i<=n;i++) {
		cin>>x>>y>>z;
		if(x>=y&&x>=z) {
			ans+=x;
			b[0].push_back(x-max(y,z));
		} else if(y>=x&&y>=z) {
			ans+=y;
			b[1].push_back(y-max(x,z));
		} else {
			ans+=z;
			b[2].push_back(z-max(x,y));
		}
	}
	for(int i=0;i<3;i++) if(b[i].size()>n/2) {
		int cnt=b[i].size()-n/2;
		sort(b[i].begin(),b[i].end());
		for(int j=0;j<cnt;j++)
			ans-=b[i][j];
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) Solve();
	return 0;
} 
