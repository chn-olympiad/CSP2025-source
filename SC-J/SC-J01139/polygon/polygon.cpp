#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans;
	for(int i=2;i<=n-1;i++){
		ans+=((n-i)%998244353);
	}
	cout<<ans%998244353<<endl;
	return 0;
}