#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=3){
		int maxn=max(a[1],max(a[2],a[3]));
		if (a[1]+a[2]+a[3]>2*maxn) cout<<1;
		else cout<<0;
	}
	else{
		int sum=0;
		for (int i=3;i<=n;i++){
			sum+=n-i+1;
			sum%=998244353;
		}
		cout<<sum;
	}
	return 0;
}
