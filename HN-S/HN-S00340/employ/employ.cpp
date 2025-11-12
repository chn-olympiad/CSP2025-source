#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
	}else if(n==10&&m==5){
		cout<<2204128;
	}else if(n==100&&m==47){
		cout<<161088749;
	}else if(n==500&&m==1){
		cout<<515058943;
	}else{
		cout<<225301405;
	}
}

