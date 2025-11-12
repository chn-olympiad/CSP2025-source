#include<bits/stdc++.h>
using namespace std;
string s;
int nums[1001000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int now=0;
	for(int i=0;i<s.length();i++){
		int num=s[i]-'0';
		if(num>=0 && num<=9){
			++now;
			nums[now]=num;
		}
	}
	sort(nums+1,nums+now+1);
	for(int i=now;i>=1;i--)
		cout<<nums[i];
	return 0;
}

