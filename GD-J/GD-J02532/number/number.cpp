#include<bits/stdc++.h>
using namespace std;
vector<char> nums;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string ans="";
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			nums.push_back(s[i]);
		}
	}
	sort(nums.begin(),nums.end(),cmp);
	for(int i=0;i<nums.size();i++){
		ans+=nums[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
