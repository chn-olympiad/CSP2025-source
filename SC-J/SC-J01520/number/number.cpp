#include <bits/stdc++.h>
using namespace std;
string s;
int nums[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		nums[i]=s[i]-48;
	}
	//test
//	for(int i=0;i<s.length();i++){
//		cout<<nums[i]<<" ";
//	}
//	cout<<endl;
	int n=s.length();
	sort(nums,nums+n,cmp);
	for(int i=0;i<s.length();i++){
		if(nums[i]>9){
            continue;
		}else{
            cout<<nums[i];
		}
	}
	return 0;
}