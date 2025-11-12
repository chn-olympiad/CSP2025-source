#include<bits/stdc++.h>
#define pb emplace_back
#define pob pop_back
using namespace std;
typedef long long ll;
const ll maxn=2007,maxm=200007;
ll n,m,c[maxn],id[maxn],ans;
string s;
bool check(void){
	ll tot=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(s[i]=='0') tot++;
		else if(tot>=c[id[i]]) tot++;
		else cnt++;
	}
	return cnt>=m;
}
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s,s=" "+s;
	for(ll i=1;i<=n;i++) cin>>c[i],id[i]=i;
	do{
		if(check()) ans++;
	}while(next_permutation(id+1,id+1+n));
	cout<<ans<<"\n";
	return 0;
}