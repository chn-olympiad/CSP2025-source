#include<bits/stdc++.h>
using namespace std;
string s;
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int nums[s.size()+1]={};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			nums[i]=int(s[i]-'0');
			n++;
		}
	}
	sort(nums,nums+s.size()+1,greater<int>());
	for(int i=0;i<n;i++)cout<<nums[i];
	return 0;
} 
