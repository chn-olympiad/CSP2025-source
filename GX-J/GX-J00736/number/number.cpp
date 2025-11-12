#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	string s;
	vector<int> nums;
	getline(cin,s);
	int n = s.size();
	if(n == 1){
		cout<<s;
		return 0;		
	}
	for(int i = 0;i < n;i++){
		if(s[i] == '1'){
			nums.push_back(1);
		}
		else if(s[i] == '2'){
			nums.push_back(2);
		}
		else if(s[i] == '3'){
			nums.push_back(3);
		}
		else if(s[i] == '4'){
			nums.push_back(4);
		}
		else if(s[i] == '5'){
			nums.push_back(5);
		}
		else if(s[i] == '6'){
			nums.push_back(6);
		}
		else if(s[i] == '7'){
			nums.push_back(7);
		}
		else if(s[i] == '8'){
			nums.push_back(8);
		}
		else if(s[i] == '9'){
			nums.push_back(9);
		}
	}
	sort(nums.begin(),nums.end());
	vector<int>::iterator it = nums.begin();
	for(it = nums.end() - 1;it >= nums.begin();it--){
		cout<<*it;
	}
	for(int i = 0;i < n;i++){
		if(s[i] == '0'){
			cout<<0;
		}
	}
	return 0;
}
