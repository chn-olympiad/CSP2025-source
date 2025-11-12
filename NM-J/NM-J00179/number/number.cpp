#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[100000],top=0;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[top++]=s[i]-'0';
		}
	}
	sort(a,a+top);
	for(int i=top-1;i>=0;i--){
		cout << a[i];
	}

	
	return 0;
}