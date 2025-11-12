#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long c[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')sum++;
	}
	if(sum<m){
		cout<<0;
	}else if(sum==s.size()){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}else{
		cout<<1;
	}
	return 0;
}
