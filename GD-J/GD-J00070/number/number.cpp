#include<bits/stdc++.h>
using namespace std;
string s;
int ans[100];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			ans[s[i]-48]++;
		}
	}
	if(!(ans[1]||ans[2]||ans[3]||ans[4]||ans[5]||ans[6]||ans[7]||ans[8]||ans[9])&&ans[0]){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=ans[i];j++){
			cout<<i;
		}
	}
	return 0;
}
