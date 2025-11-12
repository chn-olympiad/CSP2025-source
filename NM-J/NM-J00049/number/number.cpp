#inclde<iostream>
#inclde<vector>
#inclde<string>
#inclde<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	vector<int> nums=(a);
	vector<string> strs;
	for(int num : nums){
		strs.push_back(to_string(num));
	}
	sort(strs.begin(),strs.end(),[](string a,string b){
		return a+b > b+a;});
		string res; for (string s : strs) res+=s;
		cout<<(res[0]=='0' ? "0" : res)
	return 0;
} 
