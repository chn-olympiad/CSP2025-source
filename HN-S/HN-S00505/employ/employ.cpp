#include<bits/stdc++.h>
using namespace std;
#define r 998244353
int n,m;
int s[1000001];
int c[1000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		if(s[i]==0){
			cout<<0;
			exit(0);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(int i=n;i>=1;i--){
		ans=i*ans;
		ans=ans%r;
	}
	cout<<ans;
	return 0;
}
