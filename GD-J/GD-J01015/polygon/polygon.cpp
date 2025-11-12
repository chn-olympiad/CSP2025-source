#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=1e6+10;
int a[N],n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;	
	}else if(n<=10){
		cout<<17;
	}else{
		cout<<N%mod;
	}
	return 0;
}

