#include <bits/stdc++.h>
using namespace std;
string s;
int a[1123456],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++top]=s[i]-'0';
	}
	sort(a+1,a+top+1);
	for(int i=top;i>=1;i--) printf("%d",a[i]);
	return 0;
}
