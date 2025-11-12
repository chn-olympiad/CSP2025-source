#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a=" ";
	cin >> s;
	for (int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		a+=s[i];
	}
	cout << a;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
