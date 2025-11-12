#include "bits/stdc++.h"
using namespace std;

#define int long long

long long n,m;
string s;
long long a[100091];
long long res = 0;
//xi jie 91
int vis[10078];

void RED(int wow,int qs,int lq) {
	cout<<wow;
	if(lq >= m) {
		res = (res + 1) % 998244353;
		cout<<endl;
		
	}
	
	for(int i = 1;i <= n;i++) {
		if(s[i] == '1' && a[i] > qs && !vis[i]) {
			vis[i] = 1;
			RED(i,qs,lq+1);
			vis[i] = 0;
		}
		else if(s[wow] == '0' && a[i] > qs && !vis[i]) {
			vis[i] = 1;
			RED(i,qs+1,lq);
			vis[i] = 0;
		}
		else if(a[i] <= qs) {
			continue;
		}
	}
	
}


signed main() {
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	cin>>s;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++) {
		memset(vis,0,sizeof vis);
		vis[i] = 1;
		RED(1,0,0);
	}
	cout<<res % 998244353;
	
	
	return 0;
}
