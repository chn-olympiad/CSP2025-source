#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505+10;

string s;
ll n,m,a[N],ans;

inline bool check(vector<ll> v){
	
	ll cnt=0,ans=0;
	
	for(int i=0;i<s.size();i++){
		
		if(cnt>=a[v[i]]) cnt++;
		else{
			
			if(s[i]=='0') cnt++;
			else ans++;
		}
	}
	
	return ans>=m;
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	vector<ll> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	
	do{
		
		if(check(v)) ans++;
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<ans<<'\n';
	
	return 0;
}
/*

	bu yao kpg
	sui ran hen shu fu
	shou shang you bing du
	hui gan ran pg
	pg ye you du
	kou wan shou you du
	zai qu chi shi wu
	jiu rong yi zhong du
	lalalalalalalala
	bu yao kpg
	lalalalalalalala
	bu yao kpg

*/
