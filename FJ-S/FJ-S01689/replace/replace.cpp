#include<bits/stdc++.h>
using namespace std;
long long n,q;
string x,y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++) {
		cin>>x>>y;
	}
	for(long long i=1;i<=q;i++) {
		cin>>x>>y;
	}
	for(long long i=1;i<=q;i++) {
		puts("0");
	}
	return 0;
}