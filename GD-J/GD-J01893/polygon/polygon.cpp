#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[500001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=i;
	}
	cout<<ans/2%mod;
} 
