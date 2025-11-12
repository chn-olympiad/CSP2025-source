#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000110];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; //输入字符串 
	for(int i=0;i<s.length();i++){ //找出数字 
		if(s[i]<='9') a[n++]=(int)(s[i]-'0');
	}
	sort(a+0,a+n); //排序 （从小到大） 
	for(int i=n-1;i>=0;i--){ //从大到小输出 
		cout<<a[i];
	}
	return 0;
} 
