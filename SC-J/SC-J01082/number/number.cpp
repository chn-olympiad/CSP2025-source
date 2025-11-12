#include<bits/stdc++.h>
using namespace std;
string s;
int nums[100005],j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[j++]=int(s[i]-48);
		}
	}
	sort(nums,nums+j,cmp);
	for(int i=0;i<j;i++){
		cout<<nums[i];
	}
	return 0;
} 