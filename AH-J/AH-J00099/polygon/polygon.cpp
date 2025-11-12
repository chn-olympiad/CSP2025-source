#include <bits/stdc++.h>
using namespace std;
int a[50005];
int mod=998244353;
int ans=0,cnt=0;
int n;
void dfs (int dep,int he,int mx,int cnt,bool ok){
	if (cnt>=3&&he>2*mx&&!ok) {
		ans++;
		ans%=mod;
		ok=1;
	}
	//cout<<dep<<" "<<he<<" "<<mx<<" "<<cnt<<endl;
	if (dep==n+1) return ;
	if (!ok) dfs (dep+1,he,mx,cnt,0);
	else dfs (dep+1,he,mx,cnt,1);
	dfs (dep+1,he+a[dep],max (mx,a[dep]),cnt+1,0);
}
int main (){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs (1,0,0,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
