#include <bits/stdc++.h>
using namespace std;

int p[100000];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+1+n);
	long long ans=1;
	for(long long i=1;i<=m;i++){
		ans*=i;
		ans%=998244353;
	}
	long long sum=1;
	for(long long i=1;i<n-m;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<(ans*sum)%998244353;
	return 0;
} 
