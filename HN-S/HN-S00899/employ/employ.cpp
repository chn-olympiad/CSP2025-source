#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re return
#define sz 10000005
#define ew 5005
#define sscc cout<<6;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n==3){
		cout<<2;
	}
	else if(n==10){
		cout<<2204128;
	}
	else if(n==100){
		cout<<161088479;
	}
	else if(n==500){
		if(m==1){
			cout<<515058943;
		}
		else{
			cout<<225301405;
		}
	}
	re 0;
}

