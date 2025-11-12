#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
string s,v[100];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[s[i]]=v[s[i]]+s[i];
		}
	}
	for(int i='9';i>='0';i--){
		if(v[i]!="") cout<<v[i];
	}
	return 0;
} 