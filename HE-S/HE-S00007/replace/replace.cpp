#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string t1,t2;
struct node{
	string s1,s2;
}s[N];
bool cmp(node a,node b){
	if(a.s1==b.s1) return a.s2<b.s2;
	else return a.s1<b.s1;
}
void solve(){
	cin>>t1>>t2;
	ans=0;
	for(int i=1;i<=n;i++) {
		if(s[i].s1==s[i-1].s1&&s[i].s2==s[i-1].s2) continue;
		string t3=t1,t4=t2;
		while((t4.find(s[i].s2)<t4.size())&&(t3.find(s[i].s1)<t3.size())&&(t4.find(s[i].s2)==t3.find(s[i].s1))){
			if(t3.erase(t1.find(s[i].s1),t1.find(s[i].s1)+s[i].s1.size())==t4.erase(t2.find(s[i].s2),t2.find(s[i].s2)+s[i].s2.size())) ans++;
			t3.erase(t1.find(s[i].s1),t1.find(s[i].s1)+s[i].s1.size());
			t4.erase(t2.find(s[i].s2),t2.find(s[i].s2)+s[i].s2.size());
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	sort(s+1,s+n+1,cmp);
	while(q--){
		solve();
	}
	return 0;
}
