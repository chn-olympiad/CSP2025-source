#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int c;
	for(int i=1;i<=n;i++)cin>>c;
	long long ans=1;
	for(int i=n;i>n-m;i--){
		ans*=i;
		ans=ans%998244353;	
	}
	cout<<ans;
	return 0;
}

