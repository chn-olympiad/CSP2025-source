#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long int ans=1;
	int n,m,op;
	string s;
	cin>>n>>m;
	op=0;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)op++;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	if(op<m)cout<<ans;
	else cout<<0;
	return 0;
}

