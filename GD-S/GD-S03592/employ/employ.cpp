#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0)cnt++;
	}
	long long sum=1;
	for(int i=2;i<=cnt;i++){
		sum=(sum*i)%mod;
	}
	cout<<sum%mod;
	return 0;
} 
