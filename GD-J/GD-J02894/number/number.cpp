#include<bits/stdc++.h>
//#define int long long
using namespace std;
int nums[15]={0};
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		 nums[s[i]-'0']++;
	}
	}
	for(int i=9;i>=0;i--){
		while(nums[i]--){
			cout<<i;
		}
	}
	return 0;
}
