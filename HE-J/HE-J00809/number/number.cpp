//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include//#include
//20min
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,s1;
int a[1145140];
int32_t main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=s.size();
	int j=1;
	for(int i=0; i<len; ++i) {
		if(s[i]>='0'&&s[i]<='9') {
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
