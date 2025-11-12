#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int sum;
	int num;//数字的数量 
	cin>>a;//不会提取字符，省略了中间部分... 
	int s[num];
	sort (s,s+num);
	for(int i=0;i<num;i++){
		sum+=pow(10,i)*s[i];
	}
	cout<<sum;
	return 0;
} 
