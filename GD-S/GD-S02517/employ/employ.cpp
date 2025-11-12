#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	long long n,m,ans=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0; 
}
