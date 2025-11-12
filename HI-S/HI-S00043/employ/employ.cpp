#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000],sum[1000],js,ans=1;
string s;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
} 
