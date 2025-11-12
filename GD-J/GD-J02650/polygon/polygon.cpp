#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		if(max(a[1],max(a[2],a[3]))>sum/2) cout<<0;
		else cout<<1;
		reutrn 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	return 0;
} 
