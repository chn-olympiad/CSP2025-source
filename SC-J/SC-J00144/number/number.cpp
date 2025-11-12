#include <bits/stdc++.h>
using namespace std; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;//输入 
	string a="";
	//截取数字 
	for (int i=0;i<s.length();i++){
		if (s[i]>='0' && s[i]<='9'){
			a+=s[i];
		}
	}
	//从大到小 
	for (int i=0;i<a.length();i++){
		for (int j=1;j<=a.length();j++){
			if (a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	//输出 
	if (a[0]=='0') cout << 0;
	else cout <<a;
	return 0;
}