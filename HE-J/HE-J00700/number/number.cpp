#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans.push_back(s[i]);
		}
	}
	int j = ans.size();
	while(j--)
		for(int i = 1;i<ans.size();i++){
			char cnt;
			if(ans[i]>ans[i-1]){
				cnt = ans[i];
				ans[i] = ans[i-1];
				ans[i-1] = cnt;
			}
		}
	cout<<ans;
	return 0;
}
