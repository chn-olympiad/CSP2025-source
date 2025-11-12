#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			cout<<0;
			return 0;
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
}
