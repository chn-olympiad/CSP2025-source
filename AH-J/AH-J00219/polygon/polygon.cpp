#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(long long i=1;i<=n-3;i++){
		ans+=(i*(i+1))/2;
		ans%=998244353;
	}
	return 0;
}
