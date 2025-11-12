#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string s;
int a[15];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	
	
	return 0;
}
