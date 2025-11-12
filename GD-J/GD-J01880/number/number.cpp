#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char>num;
	string ans="";
	for(auto c:s){
		if('0'<=c&&c<='9') num.push_back(c);
	}
	sort(num.begin(),num.end());
	while(num.size()) ans+=num.back(),num.pop_back();
	cout<<ans;
	fcloseall();
	return 0;
}
