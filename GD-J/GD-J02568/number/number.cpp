#include<bits/stdc++.h>
#define int long long
const int N=1022;
using namespace std;
int a[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) a[s[i]]++;
	for(int i='9';i>='0';i--){
		for(int j=1;j<=a[i];j++) printf("%lld",i-'0');
	}
}
