#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int _;
int n;
ll ans;
struct cl {
	ll mx,scd;
	int id;
} s[N];
int cnt[5];
bool cmp(cl a,cl b) {
	return a.mx-a.scd<b.mx-b.scd;
}
inline void work() {
	cnt[1]=cnt[2]=cnt[3]=ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		ll x,y,z;
		cin>>x>>y>>z;
		s[i].mx=max(x,max(y,z));
		if(s[i].mx==x) s[i].id=1,s[i].scd=max(y,z);
		else if(s[i].mx==y) s[i].id=2,s[i].scd=max(x,z);
		else s[i].id=3,s[i].scd=max(x,y);
		ans+=s[i].mx;
		cnt[s[i].id]++;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++) if(cnt[s[i].id]>n/2) cnt[s[i].id]--,ans+=s[i].scd-s[i].mx;
	cout<<ans<<endl;
	return;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>_;
	while(_--) work();
	return 0;
}

