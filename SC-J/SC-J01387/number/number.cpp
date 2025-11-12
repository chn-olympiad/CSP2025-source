#include<bits/stdc++.h>
using namespace std;

string s;
char nums[1000005];
int r;

bool comp(char x,char y){
	return x>y;
}


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			nums[r]=s[i];
			++r;
		}
	}
	r--;
	sort(nums,nums+r+1,comp);
	printf("%s",nums);
	return 0;
}