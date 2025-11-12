#include <bits/stdc++.h>
using namespace std;
string s;
char t[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int z=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			t[z]=s[i];
			z++;
		}
	}
	sort(t+1,t+z+1);
	for(int i=z;i>=1;i--){
		cout << t[i];
	}
	return 0;
}
