#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second 
int n,k,a[N],ans;
vector<int> us[N];
map<int,int> ps;
set<pii> s; // r,l
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("A.txt","r",stdin);
	cin>>n>>k;
	int sum=0;
	ps[sum]=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum^=a[i];
		int v=ps[sum^k];
		if(v) {
			s.insert(mp(i,v));
			us[v].push_back(i);
		}
		ps[sum]=i+1;
	}
	int now=0;
	while(s.size()) {
		ans++;
		pii az=*s.begin(); 
//		cout<<az.fi<<" "<<az.se<<endl;
		while(now+1<=az.fi) {
			now++;
			for(auto u:us[now]) s.erase(mp(u,now));
		}
	}
	cout<<ans;
	return 0;
}
