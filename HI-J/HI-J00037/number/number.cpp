#include <bits/stdc++.h>
using namespace std;
string s;
int b[10000000],y = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	
	cin >> s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			b[i]=s[i]-'0';
			cout << b;
			y++;
			if(s.size()==1)cout << b[i];
		}	
	}
	sort(b,b+y+1);
	for(int i=y-1;i>0;i--){
		cout << b[i];
	}
	cout << "5";
	return 0;
}
	
