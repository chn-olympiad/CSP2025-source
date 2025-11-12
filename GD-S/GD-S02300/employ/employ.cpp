#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	cin>>s;
	
	int ans = 1,cnt = 0,c;
	for (int i=0;i<n;i++){
		cin>>c;
		if (c) cnt++;
	}
	for (int i=1;i<=cnt;i++){
		ans = 1LL*i*ans%MOD;
	}
	cout<<ans;
	return 0; 
}
