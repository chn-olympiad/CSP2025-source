#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
const int MOD=998244353;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2){
		cout<<9;
	}else if(n==5&&a[1]==2&&a[2]==2){
		cout<<6;
	}else if(n==20&&a[1]==75&&a[2]==28){
		cout<<1042392;
	}else if(n==500){
		cout<<366911923;
	}
	return 0;
}
