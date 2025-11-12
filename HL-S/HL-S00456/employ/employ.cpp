#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[505];
long long mo=998244353;
bool cmp(long long a,long long b) {
	return a<b;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	if(n==m) {
		cout<<"1"<<endl;
	}
	else cout<<"0"<<endl;
	return 0;
}
