#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,ans;
string s;
int a[510];
bool b[510];
void dfs(int i,int t,int k){
	if(i==n){
		if(k>=m)ans=(ans+1)%MOD;
		return;
	}
	if(k==m){
		int sum=1;
		for(int j=1;j<=n-i;j++)
			sum=sum*j%MOD;
		ans=(ans+sum)%MOD;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(b[j])continue;
		b[j]=1;
		if(a[j]<=t)t++;
		else if(s[i]=='0')t++;
		else k++;
		dfs(i+1,t,k);
		if(a[j]<=t)t--;
		else if(s[i]=='0')t--;
		else k--;
		b[j]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}

