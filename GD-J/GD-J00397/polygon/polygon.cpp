#include<bits/stdc++.h>
using namespace std;
long long n,a[5010];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2]){
		cout<<1<<endl;
		return;
	}
	cout<<0<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
