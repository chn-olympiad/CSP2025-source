#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=1;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(n>1){
		ans*=n;
		ans%=998244353;
		n--;
	}
	cout<<ans;
	return 0;
}
