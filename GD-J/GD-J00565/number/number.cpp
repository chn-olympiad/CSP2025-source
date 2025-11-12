#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
//using namespace std;
std::ifstream fin("number.in");
std::ofstream fout("number.out");
int main(){
	std::string s;
	std::vector<short> nums;
	fin>>s;
	for(char &i:s){
		if(i >= '0' and i <= '9'){
			nums.push_back(i - '0');
		}
	}
	std::sort(nums.begin(),nums.end(),std::greater<char>());
	for(size_t i = 0;i < nums.size();i++){
		fout<<nums[i];
	}
	return 0;
} 
