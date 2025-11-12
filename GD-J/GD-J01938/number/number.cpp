#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll t[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			t[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(ll j = 1;j <= t[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

