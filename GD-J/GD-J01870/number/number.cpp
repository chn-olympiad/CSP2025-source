#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],len,flag;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=1;i--){
		if(a[i]) flag=1;
		for(int j=1;j<=a[i];j++)
			cout << i;
	}
	if(flag){
		for(int i=1;i<=a[0];i++) cout << 0;
		return 0;
	}
	cout << 0;
	return 0;
} 
