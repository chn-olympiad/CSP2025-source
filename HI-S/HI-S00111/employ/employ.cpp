#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,cnt,qzh[555];
vector<int> v;
string s;
ll dp[555][555];
int main(){
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		if(s[i-1]-'0'==0){
			cnt++;
		}
		else{
			v.push_back(cnt);
		}
	}
	for(int i=1;i<=n;i++){
		int ci;
		cin>>ci;
		qzh[ci]++;
	}
	for(int i=500;i>=0;i--){
		qzh[i]+=qzh[i+1];
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<' ';
		v[i]=qzh[v[i]+1];
		cout<<v[i]<<' ';
	}
	//cout<<endl;
	//sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=v.size();i++){
		for(int j=1;j<=min(m,i);j++){
			dp[i][j]+=dp[i-1][j];
			dp[i][j]+=max(0,v[i-1]-(m-j))*dp[i-1][j-1];
			dp[i][j]%=mod;
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	ll ans=dp[v.size()][m]%mod;
	for(int i=1;i<=n-m;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
