#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[1005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>s;
	for(char i:s){
		if('0'<=i&&i<='9'){
			cnt[i]++;
		}
	}
	for(int i='9';i>='0';i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i-'0';
		}
	}
}
