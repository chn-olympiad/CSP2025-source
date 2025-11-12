#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,p,ans;
struct node {
	int mx,cmx;
	bool operator <(const node o) const {
		return mx-cmx<o.mx-o.cmx;
	}
};
vector<node>a[5];
signed main() {
	freopen("club.in","r",stdin);
//	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>t;
	while(t--) {
		a[1].clear(),a[2].clear(),a[3].clear();
		ans=p=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			int x,y,z,id;
			cin>>x>>y>>z;
			if(x>=y&&x>=z) id=1;
			if(y>=x&&y>=z) id=2;
			if(z>=x&&z>=y) id=3;
			if(x>y) swap(x,y);
			if(y>z) swap(y,z);
			if(x>y) swap(x,y);
			node now;
			now.mx=z,now.cmx=y;
			a[id].push_back(now);
			ans+=z;
		}
		if(a[1].size()>n/2) p=1;
		if(a[2].size()>n/2) p=2;
		if(a[3].size()>n/2) p=3;
		if(p) {
			sort(a[p].begin(),a[p].end());
			int cnt=a[p].size()-n/2;
			for(node v:a[p]) {
//				cout<<v.mx<<" "<<v.cmx<<"\n";
				if(cnt==0)break;
				cnt--;
				ans-=v.mx-v.cmx;
			}
		}
		cout<<ans<<"\n";
	}
} 
