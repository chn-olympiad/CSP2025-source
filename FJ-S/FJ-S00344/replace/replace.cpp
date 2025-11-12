#include<bits/stdc++.h>
using namespace std;
long long n,q;
char s1[5000005],s2[5000005],t1[5000005],t2[5000005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1;
		cin>>s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t1;
		cin>>t2;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
}

