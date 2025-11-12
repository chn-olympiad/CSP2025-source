#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0; i<(int)a.size(); i++) {
		if(a[i]>='0'&&a[i]<='9') {
			b+=a[i];
		}
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	cout<<b;
	return 0;
}
