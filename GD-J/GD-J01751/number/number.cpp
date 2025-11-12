#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
char num[1000005];string s;int leng;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			num[++leng]=s[i];
		}
	}
	sort(num+1,num+leng+1);
	for (int i=leng;i>=1;i--) cout<<num[i];
	return 0;
} 
