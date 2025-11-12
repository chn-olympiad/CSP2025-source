#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],ans=1;
long long mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=0;i<=size();i++){
		if(s[i]=='1'){
			ans*=10;
		}
	}
	cout<<mod-ans;
	return 0;
} 