#include <bits/stdc++.h>
using namespace std;
#define int long long
int const MOD=998244353;
int n,a[5010],ans=0;
void dfs(int num,int MAXN,int s,int id){
	if(s>=3){
		if(num>MAXN*2){
			ans++;
			ans%=MOD;
		}
	}
	for(int i=id+1;i<=n;i++){
		dfs(num+a[i],max(MAXN,a[i]),s+1,i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		dfs(a[i],a[i],1,i);
	}
	cout<<ans<<endl;
	return 0;
}
