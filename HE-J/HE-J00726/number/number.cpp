#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main (){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string s;
	cin >> s;
	string c;
	int len = s.size();
	for(int i = 0;i < len;i ++ ){
		if(s[i] >= '0' && s[i] <= '9'){
			c += s[i];
		}
	}
	sort(c.begin(),c.end(),cmp);
	cout << c ;
	return 0;
}
