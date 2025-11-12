#include <bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	unsigned long long ans=1;
	for(int i=1;i<=m;i++){
		ans*=i;
	}
	cout<<ans%MOD;
	return 0;
}
