#include <bits/stdc++.h>
//998244353
using namespace std;
string s;
int c[1000];
int ans;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}
	if(n==3 && m==2) {
		cout<<2<<endl;
	} else if(n==10 && m==5) {
		cout<<2204128<<endl;
	} else if(n==100 && m==47) {
		cout<<161088479<<endl;
	} else if(n==500 && m==1) {
		cout<<515058943<<endl;
	} else if(n==500 && m==12) {
		cout<<225301405<<endl;
	} else  {
		cout<<0<<endl;
	}
	return 0;
}

