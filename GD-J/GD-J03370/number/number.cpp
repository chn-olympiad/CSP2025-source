#include<bits/stdc++.h>
using namespace std;
string s;
int nums[1100000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int id=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[id++]=s[i]-'0';
//			cout<<nums[id];
		}
	}
	sort(nums,nums+id,cmp);
	for(int i=0;i<id;i++){
		cout<<nums[i];
	} 
	return 0;
}
