#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9'){
			ans.push_back(i-'0');
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	return 0;
}
