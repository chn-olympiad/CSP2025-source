#include<bits/stdc++.h>
using namespace std;
#define int long long
int cmp(int x,int y) {
	return x>y;
}
const int MODD=998244353;
int n,ans;
int a[6000];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		if(a[1]*2<(a[1]+a[2]+a[3])) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
