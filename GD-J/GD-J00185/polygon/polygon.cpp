#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
ll n,ans,p;
ll a[N];
bool f[N];
inline void dfs(ll he,ll ma,ll t,ll d)
{
	if(t==p){
		if(he>ma*2){
			ans++;
		}
		return ;
	}
	for(int i=d;i<=n;i++){
		if(f[i]==0){
			f[i]=true;
			dfs(he+a[i],max(ma,a[i]),t+1,i+1);
			f[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		p=i;
		dfs(0,0,0,1);
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
