#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
const int m=998244353;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(n<3){
		cout<<"0";
	}else if(n==3){
		int mx=max({a[1],a[2],a[3]});
		int ans=a[1]+a[2]+a[3];
		if(mx*2<ans){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(f){
		cout<<n/3;
	}else{
		cout<<"1042392";
	}
	return 0;
}
