#include<bits/stdc++.h>
using namespace std;
#define int long long
#define psb push_back
const int N=2e6+10;
int a[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
	cin>>s;
	for(char c:s) ++a[c];
	for(int i='9';i>='0';--i)
		while(a[i]--) cout<<char(i);
	return 0;
}
