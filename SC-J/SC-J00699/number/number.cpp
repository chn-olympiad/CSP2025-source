#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
string s;
int vis[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[(s[i]-'0')]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=vis[i];j>=0;j--){
			cout<<i;
		}
	}
	return 0;
}