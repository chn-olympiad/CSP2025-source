#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,s[500007],t;
map<ll,priority_queue<ll>>m;
struct un{
	ll l,r;
}u[2000007];
bool cmp(un a,un b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		s[i]^=s[i-1];
		m[s[i]].push(-i);
	}
	for(ll i=0;i<n;i++){
		while(!m[k^s[i]].empty()&&-m[k^s[i]].top()<=i){
			m[k^s[i]].pop();
		}
		if(!m[k^s[i]].empty()){
			u[++t].l=i;
			u[t].r=-m[k^s[i]].top();
		}
	}
	sort(u+1,u+t+1,cmp);
	ll cnt=-1,ans=0;
	for(ll i=1;i<=t;i++){
		if(u[i].l>=cnt){
			ans++;
			cnt=u[i].r;
		}
	}
	cout<<ans;
	return 0;
}
