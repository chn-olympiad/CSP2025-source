#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10,INF=998244353;
ll n,a[N],ans;
void dfs(ll x,ll sum,ll s){
    if(sum>a[s]) ans++;
    ans%=INF;
    for(ll i=x+1;i<s;i++) dfs(i,sum+a[i],s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
	    cin>>a[i];
    }
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) dfs(0,0,i);
	cout<<ans;
	return 0;
}
