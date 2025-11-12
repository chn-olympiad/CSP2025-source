#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int bot[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	for(int i=0;i<s.size();++i){
		if('0'<=s[i] and '9'>=s[i]){
			bot[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		while(bot[i]--){
			cout<<i;
		}
	}
	return 0;
}