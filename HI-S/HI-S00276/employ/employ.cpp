#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	long long k=1;
	for(int i=1;i<=m;i++){
		k*=i;
		k%=998244353;
	}
	printf("%lld",k);
	return 0;
} 
