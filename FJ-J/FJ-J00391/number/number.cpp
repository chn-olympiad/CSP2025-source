#include<bits/stdc++.h>
using namespace std;
string s;
string b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			b[i]=s[i];//先把字符串里面的数字提取出来 
			cout<<b[i];  //测试 
		}
		
	}
	return 0;
} 
