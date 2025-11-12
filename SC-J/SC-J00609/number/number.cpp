#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
string s;
int a[N],cnt;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i; 
	}
	return 0;
}