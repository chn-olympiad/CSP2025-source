#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000050;
string s;
int a[N];
int ans=0;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0' and s[i]<='9') {
			a[ans]= {s[i]-'0'};
			ans++;
		}
	}
	sort(a,a+ans);
	for(int i=ans-1; i>=0; i--) {
		cout<<a[i];
	}
	return 0;

}