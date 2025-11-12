#include<bits/stdc++.h>
using namespace std;
string s;
int nums[1000010];
int l=1;
int main(){
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' and s[i]<='9'){
			nums[l++]=s[i]-'0';
		}
	}
	sort(nums+1,nums+l);
	for(int i=l-1;i>=1;i--){
		cout<<nums[i];
	}
	return 0;
} 
