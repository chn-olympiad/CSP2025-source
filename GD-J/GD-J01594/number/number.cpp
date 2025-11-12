#include<bits/stdc++.h>
using namespace std;
int box[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("test.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			box[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=box[i];j++){
			cout<<i;
		}
	}
	return 0;
}

