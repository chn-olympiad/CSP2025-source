#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=600;

int n,m,c[kMaxN],dp[kMaxN][kMaxN],DP[kMaxN][kMaxN],cnt,Q[kMaxN],q[kMaxN];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i],cnt+=s[i-1]=='1',Q[c[i]]++,q[i]=q[i-1]+(s[i-1]=='0');
	}
	for(int i=1;i<=n;i++){
		Q[i]+=Q[i-1];
	}
	if(m>cnt){
		cout<<0;
		return 0;
	}
	return 0;
}
