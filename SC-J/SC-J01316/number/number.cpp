#include<bits/stdc++.h>
using namespace std;
#define int long long 
int numb[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i = 0; i < s.size(); i++){
		if(s[i]>='0' && s[i]<='9'){
			numb[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < numb[i]; j++){
			cout<<i;
		}
	}
	return 0;
}