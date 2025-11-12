#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int tong[100];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		int ch=s[i]-'0';
		if(0<=ch&&ch<=9){
			tong[ch]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(tong[i]--){
			cout<<i;
		}
	}
	return 0;
}
