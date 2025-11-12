#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	string s;
	cin>>s;
	vector<int> nums;
	for(char c:s){
		int k=c-'0';
		if(10>k && k>=0){
			nums.emplace_back(k);	
		}
		
	}
	sort(nums.begin(),nums.end(),cmp);
	for(int i:nums){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
