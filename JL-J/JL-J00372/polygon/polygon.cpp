#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[3]*2<a[1]+a[2]+a[3]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	return 0;
}