#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int k;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,a=1,cnt;
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
//		cout<<x<<' ';
		if(x!=0) cnt++;
	}
	for(int i=1;i<=cnt;i++){
		a*=i;
		a%=mod;
	}
	for(int i=1;i<=(n-cnt);i++){
		a*=i;
		a%=mod;
	}
	cout<<a;
	return 0;
}

