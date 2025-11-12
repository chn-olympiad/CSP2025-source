#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,a[5005],s;
int c(int x,int y){
	int ans=1;
	for (int i=1;i<=x;i++){
		ans*=(y+1-i);
	}
	return ans;
}
signed main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n>20) {
		for (int i=3;i<=n;i++) {
			s+=c(i,n);
			s%=N;
		}cout<<s;
	}
	else if (n<=3){
		sort(a+1,a+n+1);
		if (a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
	}
	return 0;
}
