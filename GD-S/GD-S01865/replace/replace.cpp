#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,q;
map<pair<string,string>,bool> mp,vis;
ll cnt,sz;
string t1,t2;
void dfs(ll l,ll r,string s,string s2){
	if(vis[{s,s2}]) return ;
	vis[{s,s2}]=1;
	if(mp[{s,s2}]){
//		cout << s << " " << s2 << "\n";
		cnt++;
	}
//	cout << l << " " << r << " " << s << " " << s2 << "\n";
	if(l>0){
		dfs(l-1,r,t1[l-1]+s,t2[l-1]+s2);
	}
	if(r<sz-1){
		dfs(l,r+1,s+t1[r+1],s2+t2[r+1]);
	}
	return ;
}
void solve(){
	map<ll,ll> mp2;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		ll id1=-1,id2=-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b') id1=j;
		}
		for(int j=0;j<s2.size();j++){
			if(s2[j]=='b') id2=j;
		}
		mp2[abs(id1-id2)]+=((id1+1)*(s2.size()-id2));
		mp[{s1,s2}]=1;
	}
	if(n<=1e4||q==1){
		while(q--){
			cin >> t1 >> t2;
			ll ans;
			if(t1.size()<t2.size()){
				ll l=0,r=t2.size();
				for(int i=0;i<t1.size();i++){
					if(t1[i]!=t2[i]){
						l=i;
						break ;
					}
				}
				ans=0;
				string tmp1="",tmp2="";
				for(int i=l;i<t2.size();i++){
					if(i<t1.size()) tmp1+=t1[i];
					tmp2+=t2[i];
				}
				if(mp[{tmp1,tmp2}]) ans++;
				for(int i=l;i>=0;i--){
					tmp1=t1[i]+tmp1;
					tmp2=t2[i]+tmp2;
					if(mp[{tmp1,tmp2}]) ans++;
				}
			} 
			else if(t1.size()>t2.size()){
				swap(t1,t2);
				ll l=0,r=t2.size();
				for(int i=0;i<t1.size();i++){
					if(t1[i]!=t2[i]){
						l=i;
						break ;
					}
				}
				ans=0;
				string tmp1="",tmp2="";
				for(int i=l;i<t2.size();i++){
					if(i<t1.size()) tmp1+=t1[i];
					tmp2+=t2[i];
				}
				if(mp[{tmp1,tmp2}]) ans++;
				for(int i=l;i>=0;i--){
					tmp1=t1[i]+tmp1;
					tmp2=t2[i]+tmp2;
					if(mp[{tmp2,tmp1}]) ans++;
				}
			}
			else{
				ll l=-1,r=t1.size();
				sz=t1.size();
				vis.clear();
				cnt=0;
				for(int i=0;i<t1.size();i++){
					if(t1[i]!=t2[i]&&l==-1){
						l=i;
					}
					if(t1[i]!=t2[i]&&l!=-1){
						r=i;
					}
				}
				string s="",s2="";
				for(int i=l;i<=r;i++){
					s+=t1[i];
					s2+=t2[i];
				}
				dfs(l,r,s,s2);
				ans=cnt;
			}
			cout << ans << "\n";
		}
	}
	else{
		ll ans=0;
		while(q--){
			string t1,t2;
			cin >> t1 >> t2;
			ll id1=-1,id2=-1;
			for(int j=0;j<t1.size();j++){
				if(t1[j]=='b') id1=j;
			}
			for(int j=0;j<t2.size();j++){
				if(t2[j]=='b') id2=j;
			}
			ans+=mp2[abs(id1-id2)];
			cout << ans << "\n";
		} 
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

