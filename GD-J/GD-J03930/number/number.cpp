#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<int> digits;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			digits.push_back(s[i]-'0');
		}
	}
	sort(digits.begin(),digits.end(),cmp);
	for(auto i:digits){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
