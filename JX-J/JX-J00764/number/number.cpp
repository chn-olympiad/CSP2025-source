#include <bits/stdc++.h>

using namespace std;
string str = "",ans = "";

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int len = str.size();
	for(int i = 0;i<len;i++){
		if(str[i] >='0' && str[i] <='9'){
			ans += str[i];
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans;
	len = ans.size();
	for(int  i=len - 1;i>=0;i--){
		cout<<ans[i];
	}
	
	return 0;
}
