#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	long long ans=n;
	for(int i=n-1;i>=1;i--){
		ans=(ans*i)%M;
	}
	cout<<ans;
	return 0;
}
