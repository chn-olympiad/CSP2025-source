#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5+5;
int t,n;
struct node{
	int sc[4];
	int mx1,mx2;
}a[N];
bool cmp(node b,node c){
	if(b.mx1==c.mx1) return b.mx2>c.mx2;
	return b.mx1>c.mx1;
}
int cnt[4];
inline void solve(){
	cin>>n;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			cin>>a[i].sc[j];
		}
		vector<int> p;
		for(int j=1;j<=3;++j){
			p.push_back(a[i].sc[j]);
		}
		sort(p.begin(),p.end());
		a[i].mx1 = p[2]-p[1];
		a[i].mx2 = p[1]-p[0];
	}
	sort(a+1,a+n+1,cmp);
	vector<pair<int,int>> p;
	int ans = 0;
	for(int i=1;i<=n;++i){
		p.clear();
		for(int j=1;j<=3;++j){
			p.push_back(make_pair(a[i].sc[j],j));
		}
		sort(p.begin(),p.end());
		for(int j=2;j>=0;--j){
			int c = p[j].first,k = p[j].second;
			if(cnt[k]<n/2){
				ans+=c;
				cnt[k]++;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		solve();
	}
}


