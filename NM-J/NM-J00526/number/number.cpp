#include<iostream>
//字符串筛选数字 桶排序从大到小输出即可
//时间复杂度O(n+m),S的长度不超过10^6,数字只有0~9,应该是没什么问题
//好水，不会有坑吧ccf 
//CSP-J2025 T1 ylqg
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[100] = {0};
	string s;
	cin>>s;
	for(int i=0;i< s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	
	return 0;
}
