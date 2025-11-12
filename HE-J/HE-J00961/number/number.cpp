#include <bits/stdc++.h>
using namespace std;

const int N=1000;
string s;
int t[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cin.tie(nullptr);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
