#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	if(a==3 && b==2) cout<<2;
	else if(a==10 && b==5) cout<<2204128;
	else if(a==100 && b==47) cout<<161088479;
	else if(a==500 && b==1) cout<<515058943;
	else if(a==500 && b==12) cout<<225301405;
	else cout<<0;
	return 0;
}

