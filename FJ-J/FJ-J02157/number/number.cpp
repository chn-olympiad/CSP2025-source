#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
	freopen("number.in","w",NULL);
	freopen("number.out","o",NULL);
	string s;
	int max=0,c=0,znum=0;
	cin>>s;
	vector<int> nums(s.size());
	for(int i=0;i<s.size();i++){
		char ch = s[i];
		if(ch>'0' && ch<='9'){
			nums[c++]=ch-'0';
		}else if(ch == '0'){
			znum++;
		}
	}
	for(int i=0;i<nums.size()-1;i++){
		for(int j =i;j<nums.size();j++){
			if(nums[i]<nums[j]){
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	for(int i=0;i<nums.size()&&nums[i]!=0;i++){
		max=max*10+nums[i];
	}
	cout<<max;
	while(znum--){
		cout<<0;
	}
	return 0;
}
