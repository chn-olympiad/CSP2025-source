#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200005],s2[200005];
string t1,t2;
ll solve(string t1,string t2){
	ll ans=0;
	for(int i=1;i<=n;i++){
		string t3=t1;
		ll ff=t3.find(s1[i]);
		if(ff==-1)continue;
		t3.insert(ff+s1[i].size(),s2[i]);
		t3.erase(ff,s1[i].size());
		ans+=t3==t2;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		cout<<solve(t1,t2)<<'\n';
	}
	return 0;
}
