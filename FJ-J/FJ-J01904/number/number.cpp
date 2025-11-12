#include<bits/stdc++.h>
using namespace std;
int nums[10010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int len=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			nums[i]=s[i]-'0';
			len++;				
		}
	}
	for(int m=0;m<=len-1;m++){
		for(int n=0;n<=m-1;n++){
			if(nums[n]<nums[m]){
				swap(nums[m],nums[n]);
			}
		}
	}
	for(int i=0;i<len;i++){
		cout<<nums[i];
	}
	return 0;
}
