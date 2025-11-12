#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	int nums[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(nums[i]>0){
			ans+=(char)('0'+i);
			nums[i]--;
		}
	}
	cout<<ans;
	return 0;
} 
