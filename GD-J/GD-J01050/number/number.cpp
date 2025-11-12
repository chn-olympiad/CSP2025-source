#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int js[11]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int tv=s[i]-'0';
		if(tv>=0&&tv<=9){
			js[tv]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(js[i]--){
			cout<<i;
		}
	}
	return 0;
}
