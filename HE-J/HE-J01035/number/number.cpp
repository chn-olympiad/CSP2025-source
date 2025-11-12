#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int t[10];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]--){
			cout<<i;
		}
	}
	return 0;
}

