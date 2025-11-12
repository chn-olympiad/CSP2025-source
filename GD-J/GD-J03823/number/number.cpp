#include <bits/stdc++.h>
using namespace std;
bool cmp(const char &c1,const char &c2){
	return c1>=c2;
}
int main(){
	freopen("number3.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin >> s;
	for (char c:s){
		if (c>='0' && c<='9'){
			s1+=c;
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	cout << s1; 
	return 0;
} 
