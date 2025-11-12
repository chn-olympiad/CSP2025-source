#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int mp[15];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto v:s){
		if(v>='0'&&v<='9'){
			mp[v-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++){
			cout<<i;
		}
	}
	return 0;
}