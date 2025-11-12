#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c[105];
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=0;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
	}
	n-=cnt;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]!='1'&&n==m){
			cout<<0;
			return 0;
		}
		if(s[i]!='1'){
			cout<<m*(s.size()-1);
			return 0;
		}
	}
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}
