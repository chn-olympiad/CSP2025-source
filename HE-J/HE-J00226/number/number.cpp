#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int nums[1000005]={0},zeros=0;
int main(){
	string a;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='1' && a[i]<='9'){
			nums[i]=a[i]-'0';
		}
		if(a[i]=='0') zeros++;
	}
	sort(nums,nums+1000005,cmp);
	for(int i=0;i<1000005;i++){
		if(nums[i]==0)break;
		cout<<nums[i];
	}
	for(int i=0;i<zeros;i++){
		cout<<0;
	}
	return 0;
}
