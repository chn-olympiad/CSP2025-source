#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;cin>>str;
	vector<char>nums;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9' && str[i]>='0')nums.push_back(str[i]);
	}
	sort(nums.begin(),nums.end(),greater<int>());
	string ans="";
	for(int i=0;i<nums.size();i++)ans+=nums[i];
	cout<<ans;
	return 0;
}