#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	string s;
	int sum=0,nums[1000000],cnt=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			nums[cnt++]=s[i]-'0';
	}
	sort(nums+0,nums+cnt,cmp);
	for(int i=0;i<cnt;i++){
		sum*=10;
		sum+=nums[i];
	}
	cout<<sum;
	return 0;
}
 
