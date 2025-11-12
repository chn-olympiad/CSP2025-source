#include <bits/stdc++.h>
using namespace std;

int b(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int nums[1000000]={};
	string in;
	int n=0;
	cin>>in;
	for(int i=0;i<in.size();i++){
		if(in[i]>='0'&&in[i]<='9'){
			nums[n]=in[i]-'0';
			n++;
		}
	}
	sort(nums,nums+n,b);
	for(int i=0;i<n;i++){
		cout<<nums[i];
	}
	return 0;
}
