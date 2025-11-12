#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s[505],c[505],k[505],ans;
vector<ll> v;
bool check(vector<ll>& v){
	ll ref=0,ly=0;
	for(int i=1;i<=n;i++){
		if(ref>=c[v[i]]){ref++;continue;}
		if(!s[i])ref++;
		else ly++;
	}
	return ly>=m;
}
void dfs(ll x){
	if(x>n){ans+=check(v);return;}
	for(int i=1;i<=n;i++)
		if(!k[i]){
			k[i]=1;
			v.push_back(i);
			dfs(x+1);
			k[i]=0;
			v.pop_back();
		}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(int i=0;i<n;i++)
		s[i+1]=ss[i]-48;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	v.push_back(0);
	dfs(1);
	cout<<ans;
	return 0;
}
