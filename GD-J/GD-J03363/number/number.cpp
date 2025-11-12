#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
string s;
int n,a[maxn];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=s.size()-1;i>=0;i--){
		const char ch=s[i];
		if(((int)'0'<=(int)ch)&&((int)ch<=(int)'9')){++n;a[n]=(int)ch-(int)'0';}
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
}

