#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int nums[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	int j=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			nums[j]=s[i]-'0';
			j++;
		}
	}
	sort(nums,nums+j);
	for(int i=j-1;i>=0;i--){
		cout<<nums[i];
	}
	return 0;
}