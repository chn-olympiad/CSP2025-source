#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int idx;
	for(int i=1;i<=n;i++){
		if(c[i]==1) idx=i;
	}
	int ans=1;
	for(int i=1;i<=n-idx;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
