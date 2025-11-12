#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
//	string a;
//	cin>>a;
//	int ss=0;
//	for (int i=1;i<=n;i++){
//		int num;cin>>num;
//		if (num==0) ss++;
//	}
//	ss=47;
	int s=1;
	for (int i=2;i<n;i++) s=(s*i)%998244353;
	cout<<s;
}
