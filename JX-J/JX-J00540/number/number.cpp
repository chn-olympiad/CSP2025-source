//number
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e6+5;

int n;
string s;

int sum[15];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	
	cin>>s;
	n=s.size();
	s=' '+s;
	
	for(int i=1;i<=n;i++){
		if('0'<=s[i] && s[i]<='9'){
			sum[s[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			cout<<i;
		}
	}
	cout<<emdl;
	
	return 0;
}
/*
0001
*/
